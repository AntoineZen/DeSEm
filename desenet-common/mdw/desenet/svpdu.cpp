/*
 * svpdu.cpp
 *
 *  Created on: Dec 2, 2015
 *      Author: antoine
 */

#include <svpdu.h>

namespace desenet {

SvPDU::SvPDU() : _buffer(7), _size(0)
{
	// TODO Auto-generated constructor stub

}

void SvPDU::setSize(std::size_t size)
{
	_size = size;
}

std::size_t SvPDU::size()
{
	return _size;
}

SharedByteBuffer& SvPDU::buffer(){
	return _buffer;
}

SvPDU::~SvPDU() {
	// TODO Auto-generated destructor stub
}



} /* namespace desenet */
