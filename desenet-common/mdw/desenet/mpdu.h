/*
 * Mpdu.h
 *
 *  Created on: Dec 2, 2015
 *      Author: antoine
 */

#ifndef DESENET_MPDU_H_
#define DESENET_MPDU_H_

#include <frame.h>
#include "svpdu.h"
#include "mdw/containers/sharedbytebuffer.hpp"

namespace desenet {

class Mpdu: public Frame {

public:
public:
	Mpdu();
	virtual ~Mpdu();

	void add(uint8_t group, SvPDU& svPdu);

private:
	uint8_t* insert_ptr;
};

} /* namespace desenet */

#endif /* DESENET_MPDU_H_ */
