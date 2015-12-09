/*
 * evpdu.h
 *
 *  Created on: Dec 9, 2015
 *      Author: antoine
 */

#ifndef DESENET_EVPDU_H_
#define DESENET_EVPDU_H_

#include <epdu.h>

namespace desenet {

class EvPDU: public Epdu {
public:
	EvPDU();
	virtual ~EvPDU();

	void setId(uint8_t id);

	uint8_t id();

	uint8_t header();

private:
	uint8_t _event_id;
};

} /* namespace desenet */

#endif /* DESENET_EVPDU_H_ */
