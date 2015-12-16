/*
 * evpdu.cpp
 *
 *  Created on: Dec 9, 2015
 *      Author: antoine
 */

#include <evpdu.h>

namespace desenet {


EvPDU::EvPDU(): Epdu() {
	setSize(1);
}

void EvPDU::setId(uint8_t id)
{
	_event_id = id;
}

uint8_t EvPDU::id()
{
	return _event_id;
}

uint8_t EvPDU::header()
{
	return ((_event_id & 0x0F) << 3) | (_size & 0x07) | 0x80;
}

} /* namespace desenet */
