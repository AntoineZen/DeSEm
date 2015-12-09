#include <assert.h>
#include <array>
#include <list>
#include <map>
#include <vector>
#include <utility>
#include "platform-config.h"
#include "desenet/frame.h"
#include "desenet/beacon.h"
#include "abstractapplication.h"
#include "factory.h"
#include "board/ledcontroller.h"
#include "networkentity.h"
#include "mpdu.h"


using std::array;
using std::list;
using std::map;
using std::make_pair;
using std::bind;
using std::pair;
using std::vector;

using desenet::sensor::NetworkEntity;

NetworkEntity * NetworkEntity::_pInstance(nullptr);

NetworkEntity::NetworkEntity()
 : _pTimeSlotManager(nullptr),
   _pTransceiver(nullptr)
{
	assert(!_pInstance);		// Only one instance allowed
	_pInstance = this;

}

NetworkEntity::~NetworkEntity()
{
}

void NetworkEntity::initialize()
{
}

void NetworkEntity::initializeRelations(ITimeSlotManager & timeSlotManager, NetworkInterfaceDriver & transceiver)
{
	_pTimeSlotManager = &timeSlotManager;
    _pTransceiver = &transceiver;

     // Set the receive callback between transceiver and network. Bind this pointer to member function
    transceiver.setReceptionHandler(std::bind(&NetworkEntity::onReceive, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));

    //_pTimeSlotManager->setObserver(this);
}

void NetworkEntity::svSyncRequest(AbstractApplication* app)
{
	this->_pSyncAppList.push_back(app);
}

bool NetworkEntity::svPublishRequest(AbstractApplication* app,  SvGroup group)
{
	if(this->_pPubAppList[group] == NULL)
	{
		this->_pPubAppList[group] = app;
		return true;
	}
	return false;
}

/**
 * Called by the NetworkInterfaceDriver (layer below) after reception of a new frame
 */
void NetworkEntity::onReceive(NetworkInterfaceDriver & driver, const uint8_t * const buffer, size_t length)
{
	UNUSED(driver);
	Frame frame = Frame::useBuffer(buffer, length);

	// Is this frame valid ?
	if (frame.isValid())
	{
		// Right, we have valid frame, that type is this ?
		if (frame.type() == desenet::FrameType::Beacon)
		{
			// Frame is bacon, we need to ...

			// ... 1) "Cast" it to a Beacon object ...
			Beacon b(frame);

			// ... 2) Sync with the time slot manager (if any)
			if (_pTimeSlotManager)
			{
				_pTimeSlotManager->onBeaconReceived(b.slotDuration());
			}

			// ... 3) sync the apps that have registered to be notified for the sync...
			for(ApplicationSyncList::iterator synced = _pSyncAppList.begin(); synced != _pSyncAppList.end(); synced++)
			{
				(*synced)->svSyncIndication(b.networkTime());
			}

			// ... 4) Extract the valuable data from it!
			_pSvGroupMask = b.svGroupMask();

		}
		else if (frame.type() == desenet::FrameType::MPDU)
		{
			Trace::outln("Frame is a MPDU");
			Trace::outln(frame.toString());
		}
		else
		{
			Trace::outln("Frame is unkonwn");
			// This should never happen !
		}
	}
}


void NetworkEntity::onTimeSlotSignal(const ITimeSlotManager & timeSlotManager, const ITimeSlotManager::SIG & signal)
{
	//uint8_t dummy_data[] = {0x01, 0x02, 0x03};
	//Trace::outln("Time Slot event");
	if (signal == ITimeSlotManager::OWN_SLOT_START)
	{
		//Trace::outln("Sending");
		//Frame dummy = Frame::copyFromBuffer(dummy_data, 3);
		//transceiver() << dummy;

		Mpdu mpdu = Mpdu();

		for(uint8_t i=0; i < _pPubAppList.size(); i++)
		{
			if(_pSvGroupMask[i] && _pPubAppList[i] != NULL)
			{
				SvPDU svPdu = SvPDU();
				svPdu.setSize(_pPubAppList[i]->svPublishIndication(i, svPdu.buffer()));

				mpdu.add(i,svPdu);

			}
		}

		Trace::outln("Sending %s", mpdu.toString());
		transceiver() << mpdu;


	}

}
