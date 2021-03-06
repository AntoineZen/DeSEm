#ifndef FACTORY_H
#define FACTORY_H

#include <assert.h>
#include "platform-config.h"
#include "desenet/sensor/net.h"
#include "interfaces/imonochromedisplay.h"
#include "app/accelerometerapplication.h"
#include "app/joystickapplication.h"
#include "board/accel/accelerometer.h"

class MeshSimBoard;
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

	MeshSimBoard & meshSimBoard() const;

	app::AccelerometerApplication & accelerometerApplication() const;
	app::JoystickApplication& joystickApplication() const;
	board::Accelerometer & accelerometer() const;

	Net & net() const;
	SimpleDisplay & display();
	LedController & ledController() const;

protected:
	static Factory * _pInstance;
};

#endif
