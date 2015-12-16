/*
 * Mpdu.h
 *
 *  Created on: Dec 2, 2015
 *      Author: antoine
 */

#ifndef DESENET_MPDU_H_
#define DESENET_MPDU_H_

#include <frame.h>
#include "epdu.h"
#include "mdw/containers/sharedbytebuffer.hpp"

namespace desenet {

class Mpdu: public Frame {

public:

	static const uint8_t MAX_EPDU_COUNT;
public:
	Mpdu();
	virtual ~Mpdu();

	bool add(Epdu& svPdu);

	uint8_t ePduCount();

private:
	uint8_t* insert_ptr;
};

} /* namespace desenet */

#endif /* DESENET_MPDU_H_ */
