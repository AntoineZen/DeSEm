#ifndef FACTORY_H
#define FACTORY_H

#include <assert.h>
#include "platform-config.h"
#include "desenet/sensor/net.h"
#include "interfaces/imonochromedisplay.h"
#include "app/accelerometerapplication.h"
#include "app/joystickapplication.h"
#include "board/accel/accelerometer.h"
#include "board/joystick.h"

class SimpleDisplay;
class LedController;

/**
 * @brief Provides access to general instances. Initializes and builds the application.
 */
class Factory
{
public:
	Factory(int argc, char ** argv);

	void buildApplication();

	static Factory & instance() { assert(_pInstance); return *_pInstance; }

	app::AccelerometerApplication & accelerometerApplication() const;
	board::Accelerometer & accelerometer() const;

	app::JoystickApplication& joystickApplication() const;

	Net & net() const;
	SimpleDisplay & display();
	LedController & ledController() const;

protected:
	static Factory * _pInstance;
};

#endif
