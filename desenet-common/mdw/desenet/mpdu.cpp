/*
 * Mpdu.cpp
 *
 *  Created on: Dec 2, 2015
 *      Author: antoine
 */

#include <mpdu.h>
#include <cstring>
#include "platform-config.h"
#include "mdw/desenet/sensor/net.h"

namespace desenet {

Mpdu::Mpdu() : Frame(Frame::Mtu)
{
	memset(buffer() + Frame::HEADER_SIZE, 0, 1);	// Set first field in payload to zero
    setDestination(SENSOR_ADDRESS);
    setType(FrameType::MPDU);

    SlotNumber slot = Net::instance().slot();

    memcpy(buffer() + Frame::HEADER_SIZE, &slot, 1);

    insert_ptr = buffer() + 3;

}

Mpdu::~Mpdu() {
	// TODO Auto-generated destructor stub
}

} /* namespace desenet */


void Mpdu::add(SvPDU& svPdu)
{
	// Increment
	buffer()[2]++;

	memcpy(insert_ptr, svPdu.buffer().data(), svPdu.size());

	insert_ptr += svPdu.size();

}
