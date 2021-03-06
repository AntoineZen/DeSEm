#ifndef SENSOR_NETWORK_ENTITY_H
#define SENSOR_NETWORK_ENTITY_H

#include <assert.h>
#include <list>
#include <array>
#include "platform-config.h"
#include "desenet/desenet.h"
#include "desenet/networkinterfacedriver.h"
#include "itimeslotmanager.h"

using desenet::NetworkInterfaceDriver;
using namespace desenet;

class LedController;
class Net;
namespace desenet {
namespace sensor {	// sensor namespace

class AbstractApplication;

/**
 * @brief Implements the desenet protocol on the network layer.
 */
class NetworkEntity: ITimeSlotManager::Observer
{
	friend class desenet::sensor::AbstractApplication;
	friend class ::Net;

public:
	NetworkEntity();
	virtual ~NetworkEntity();

	void initialize();																						///< Initializes the instance.
	void initializeRelations(ITimeSlotManager & timeSlotManager, NetworkInterfaceDriver & transceiver);		///< Initializes all relations needed by the instance.

	inline static NetworkEntity & instance() { assert(_pInstance); return *_pInstance; }					///< Returns reference to single instance.

	void svSyncRequest(AbstractApplication* app);

	bool svPublishRequest(AbstractApplication* app, SvGroup group);

	void evPublishRequest(EvId id, const SharedByteBuffer & evData);

protected:
	/**
	 * @brief Holds event information.
	 */
    struct EventElement
    {
        EventElement(EvId id, const SharedByteBuffer & data)
         : id(id), data(data)
        {}

        EvId id;						///< Event identifier (ex. EVID_JOYSTICK).
        const SharedByteBuffer data;	///< Data that goes together with the event.
    };

	// desenet::NetworkInterfaceDriver::Callback callback
protected:
	/**
	 * @brief Called by the lower layer after reception of a new frame
	 */
	virtual void onReceive(NetworkInterfaceDriver & driver, const uint8_t * const buffer, size_t length);

	virtual void onTimeSlotSignal(const ITimeSlotManager & timeSlotManager, const ITimeSlotManager::SIG & signal);

protected:
	inline ITimeSlotManager & timeSlotManager() const { assert(_pTimeSlotManager); return *_pTimeSlotManager; }	///< Internal access to TimeSlotManager
	inline NetworkInterfaceDriver & transceiver() const { assert(_pTransceiver); return *_pTransceiver; }		///< Internal access to Transceiver

protected:
	typedef std::list<AbstractApplication *> ApplicationSyncList;
	typedef std::array<AbstractApplication *, 16> ApplicationPublishersArray;
	typedef std::list<EventElement> EventElementList;



protected:
	static NetworkEntity * _pInstance;				///< Pointer to single instance.
	ITimeSlotManager * _pTimeSlotManager;			///< Pointer to TimeSlotManager.
	NetworkInterfaceDriver * _pTransceiver;			///< Pointer to transceiver.

	ApplicationSyncList _pSyncAppList;
	ApplicationPublishersArray _pPubAppList;
	EventElementList _pEventElementList;

	desenet::SvGroupMask _pSvGroupMask;

};

} // sensor
} // desenet
#endif // SENSOR_NETWORK_ENTITY_H
