/*
 * svpdu.h
 *
 *  Created on: Dec 2, 2015
 *      Author: antoine
 */

#ifndef DESENET_SVPDU_H_
#define DESENET_SVPDU_H_

#include "mdw/containers/sharedbytebuffer.hpp"
using namespace hei;


namespace desenet {

class SvPDU {
public:
	SvPDU();
	virtual ~SvPDU();

	void setSize(std::size_t size);

	std::size_t size();

	SharedByteBuffer& buffer();

private:

	SharedByteBuffer _buffer;
	std::size_t _size;
};

} /* namespace desenet */

#endif /* DESENET_SVPDU_H_ */
