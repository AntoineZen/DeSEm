/*
 * joystickapplication.h
 *
 *  Created on: Dec 9, 2015
 *      Author: antoine
 */

#ifndef JOYSTICKAPPLICATION_H_
#define JOYSTICKAPPLICATION_H_

#include <sensor/abstractapplication.h>

namespace app {

class JoystickApplication: public sensor::AbstractApplication {
public:
	JoystickApplication();
	virtual ~JoystickApplication();
};

} /* namespace desenet */

#endif /* JOYSTICKAPPLICATION_H_ */
