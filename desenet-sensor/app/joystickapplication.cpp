/*
 * joystickapplication.cpp
 *
 *  Created on: Dec 9, 2015
 *      Author: antoine
 */

#include <app/joystickapplication.h>
#include <board/joystick.h>
#include <mdw/desenet/sensor/net.h>
#include <platform-config.h>

namespace app {

JoystickApplication::JoystickApplication() {
	// TODO Auto-generated constructor stub

}

JoystickApplication::~JoystickApplication() {
	// TODO Auto-generated destructor stub
}

void JoystickApplication::initialize()
{
	Joystick::instance().setObserver(this);
}

void JoystickApplication::onPositionChange( IJoystick::Position position )
{
	Trace::outln("Joystick moved %d", position);

	SharedByteBuffer b(1);
	b[0] = position;

	Net::instance().entity().evPublishRequest(EVID_JOYSTICK, b);
}

} /* namespace app */
