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
#include "svpdu.h"
#include "evpdu.h"


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

void NetworkEntity::evPublishRequest(EvId id, const SharedByteBuffer & evData)
{
	_pEventElementList.push_back(EventElement(id, evData));
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

			// ... 5) Blink the led
			Factory::instance().ledController().flashLed(0);

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
	//Trace::outln("Time Slot event");
	if (signal == ITimeSlotManager::OWN_SLOT_START)
	{
		//Trace::outln("Sending");

		// Create a mPDU frame
		Mpdu mpdu = Mpdu();

		// Browse the list of the application that have registered for sample value publications
		for(uint8_t i=0; i < _pPubAppList.size(); i++)
		{
			// If the Sv Group is enabled in beacon
			if(_pSvGroupMask[i] && _pPubAppList[i] != NULL)
			{
				// Create a SvPDU object.
				SvPDU svPdu = SvPDU(i);
				// Request the application to fill it,
				svPdu.setSize(_pPubAppList[i]->svPublishIndication(i, svPdu.buffer()));
				// Add the SvPdu to the mPdu.
				mpdu.add(svPdu);

			}
		}

		// Place as much event that an mPDU can take from the event queue.
		// As long we have enent in the queue and that we have room in the mPdu
		while( _pEventElementList.size() && mpdu.ePduCount() < Mpdu::MAX_EPDU_COUNT)
		{
			// Create a Ev ePDU object
			EvPDU evPdu = EvPDU();

			// take the data from the enet at the front of queue
			evPdu.buffer() = _pEventElementList.front().data;
			evPdu.setId(_pEventElementList.front().id);

			// Add the Ev ePDU to the mPDU.
			if (mpdu.add(evPdu))
			{
				// if the Event can be added to the mPDU, we can remove it from the queue
				_pEventElementList.pop_front();
			}
			else
			{
				// if there was enough place left in the mPDU, stop adding Ev PDU to it, so break the loop
				break;
				// As the event was not removed from the queue, it will be sent on the next time slot.
			}

		}


		// Send the MPDU (Request the transceiver to put the bits in the air).
		transceiver() << mpdu;
		//Trace::outln("Sending %s", mpdu.toString());
	}

}
