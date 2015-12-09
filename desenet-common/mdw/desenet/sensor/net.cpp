#include "platform-config.h"
#include "factory.h"
#include "net.h"

// External function in order to instanciate a NIC.
extern desenet::NetworkInterfaceDriver *instanciateNic(uint32_t address, const std::string &name);

Net::Net()
 : _pNetworkInterfaceDriver(nullptr), _pSlotNumber(0)
{
}

Net::~Net()
{
}

void Net::initialize(const desenet::SlotNumber & slotNumber)
{
	char sensorName[16];
	
	_networkEntity.initialize();
	_timeSlotManager.initialize(slotNumber);

	snprintf(sensorName, 16, "Sensor %d", slotNumber);

	_pNetworkInterfaceDriver = instanciateNic(*(uint32_t *)SENSOR_ADDRESS.data(), sensorName);
	_pNetworkInterfaceDriver->initialize();

	_networkEntity.initializeRelations(_timeSlotManager, *_pNetworkInterfaceDriver);

	_timeSlotManager.setObserver(_networkEntity);

	_pSlotNumber = slotNumber;
}

void Net::start()
{
	_timeSlotManager.start();
}

//static
Net & Net::instance()
{
	return Factory::instance().net();
}

desenet::SlotNumber Net::slot(void)
{
	return _pSlotNumber;
}
