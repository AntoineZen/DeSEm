#include "platform-config.h"
#include "board/board.h"
#include "trace/trace.h"
#include "display/simpledisplay.h"
#include "board/ledcontroller.h"
#include "factory.h"

desenet::SlotNumber __SLOT_NUMBER = DESENET_SLOT_NUMBER;	///< Slot number variable that may be changed at startup.

Factory * Factory::_pInstance(nullptr);

Factory::Factory(int argc, char ** argv)
{
	UNUSED(argc); UNUSED(argv);

	assert(!_pInstance);
	_pInstance = this;
}

void Factory::buildApplication()
{
	board::initialize();	// Initialize board specific stuff

	Trace::outln("");
	Trace::outln("---------------------------------------------");
	Trace::outln("-- Starting Desenet %s                 --", DESNET_NODE_NAME);
	Trace::outln("-- Compiled: %s %s          --", __DATE__, __TIME__);
	Trace::outln("---------------------------------------------");

	//
	// Initialize objects
	//
	ledController().initialize();
	accelerometer().initialize();
	accelerometerApplication().initialize();
	net().initialize(__SLOT_NUMBER);
	display().initialize();
	Joystick::instance().initialize();
	joystickApplication().initialize();

	//
	// Initialize relations
	//

	// Draw Title on display
	display().clear();
	display().drawText(DESNET_NODE_NAME, 22, 0);
	display().drawLine({1, 8}, {SimpleDisplay::X_MAX - 1, 8});

	char str[32];
	sprintf(str, "Slot #: %d", __SLOT_NUMBER);
	display().drawText(str, 0, 2);

	ledController().start();
	net().start();
	accelerometerApplication().start();
}

app::AccelerometerApplication & Factory::accelerometerApplication() const
{
	static app::AccelerometerApplication accelerometerApp;

	return accelerometerApp;
}

board::Accelerometer & Factory::accelerometer() const
{
	static board::Accelerometer accelerometer;

	return accelerometer;
}

app::JoystickApplication& Factory::joystickApplication() const
{
	static app::JoystickApplication joyApp;

	return joyApp;
}

Net & Factory::net() const
{
	static Net net;

	return net;
}

SimpleDisplay & Factory::display()
{
	static SimpleDisplay display;

	return display;
}

LedController & Factory::ledController() const
{
	static LedController ledController;

	return ledController;
}
