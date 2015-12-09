/*
 * epdu.cpp
 *
 *  Created on: Dec 9, 2015
 *      Author: antoine
 */

#include <epdu.h>

namespace desenet {

Epdu::Epdu(): _buffer(7), _size(0)
{
	// TODO Auto-generated constructor stub

}

void Epdu::setSize(std::size_t size)
{
	_size = size;
}

std::size_t Epdu::size()
{
	return _size;
}



SharedByteBuffer& Epdu::buffer(){
	return _buffer;
}

Epdu::~Epdu() {
	// TODO Auto-generated destructor stub
}

} /* namespace desenet */
