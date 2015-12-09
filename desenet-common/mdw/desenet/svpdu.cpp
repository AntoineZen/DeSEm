/*
 * svpdu.cpp
 *
 *  Created on: Dec 2, 2015
 *      Author: antoine
 */

#include <svpdu.h>

namespace desenet {

SvPDU::SvPDU(SvGroup group) : Epdu(),_group(group)
{
	// TODO Auto-generated constructor stub

}


void SvPDU::setGroup(SvGroup group)
{
	_group = group;
}

SvGroup SvPDU::group()
{
	return _group;
}

uint8_t SvPDU::header()
{
	return ((_group & 0x0F) << 3) | (_size & 0x07);
}


SvPDU::~SvPDU() {
	// TODO Auto-generated destructor stub
}


} /* namespace desenet */
