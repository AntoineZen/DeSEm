/*
 * svpdu.h
 *
 *  Created on: Dec 2, 2015
 *      Author: antoine
 */

#ifndef DESENET_SVPDU_H_
#define DESENET_SVPDU_H_

#include "mdw/containers/sharedbytebuffer.hpp"

#include "epdu.h"

using namespace hei;


namespace desenet {

class SvPDU: public Epdu {
public:
	SvPDU(SvGroup group);
	virtual ~SvPDU();

	void setGroup(SvGroup group);

	SvGroup group();


	uint8_t header();


private:
	SvGroup _group;
};

} /* namespace desenet */

#endif /* DESENET_SVPDU_H_ */
