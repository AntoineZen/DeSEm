/*
 * epdu.h
 *
 *  Created on: Dec 9, 2015
 *      Author: antoine
 */

#ifndef DESENET_EPDU_H_
#define DESENET_EPDU_H_
#include "mdw/containers/sharedbytebuffer.hpp"
#include "types.h"


namespace desenet {

class Epdu {
public:
	Epdu();
	virtual ~Epdu();

	void setSize(std::size_t size);

	std::size_t size();

	virtual uint8_t header()=0;

	SharedByteBuffer& buffer();

protected:

	SharedByteBuffer _buffer;
	std::size_t _size;
};

} /* namespace desenet */

#endif /* DESENET_EPDU_H_ */
