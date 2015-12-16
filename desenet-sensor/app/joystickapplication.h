/*
 * joystickapplication.h
 *
 *  Created on: Dec 9, 2015
 *      Author: antoine
 */

#ifndef JOYSTICKAPPLICATION_H_
#define JOYSTICKAPPLICATION_H_

#include <sensor/abstractapplication.h>
#include <board/interfaces/ijoystickobserver.h>

namespace app {

class JoystickApplication:  public IJoystickObserver,
                            public sensor::AbstractApplication
{
public:
	JoystickApplication();
	virtual ~JoystickApplication();

	void initialize();

	// IJoystickObjserver interface
public:
	void onPositionChange( IJoystick::Position position );

};

} /* namespace desenet */

#endif /* JOYSTICKAPPLICATION_H_ */
