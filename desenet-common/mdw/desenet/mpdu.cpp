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

#define E_PDU_SID_OFFSET 0
#define E_PDU_COUNT_OFFSET 1
#define E_PDU_PAYLOAD_OFFSET 2

#define E_PDU_FTYPE_MASK 0x80

namespace desenet {

const uint8_t Mpdu::MAX_EPDU_COUNT = 255;

Mpdu::Mpdu() : Frame(Frame::Mtu)
{
	//memset(buffer() + Frame::HEADER_SIZE, 0, 1);	// Set first field in payload to zero
    setDestination(GATEWAY_ADDRESS);

    // Set the ePDU count to zero
	buffer()[Frame::HEADER_SIZE + E_PDU_COUNT_OFFSET] = 0;

    // Get our slot nuber for the NET layer
    uint8_t slot = Net::instance().slot();

    // Copy the "Frametype+ Sensor ID" in the buffer
    memcpy(buffer() + Frame::HEADER_SIZE, &slot, 1);

    // Setup the insertion pointer
    insert_ptr = buffer() + Frame::HEADER_SIZE + E_PDU_PAYLOAD_OFFSET;

    setType(FrameType::MPDU);

    setLength(Frame::HEADER_SIZE + E_PDU_PAYLOAD_OFFSET);


}

Mpdu::~Mpdu() {
	// TODO Auto-generated destructor stub
}

} /* namespace desenet */


bool Mpdu::add(Epdu& svPdu)
{
	// Check that we have enough place
	if (svPdu.size() + length() + 1 > Mtu)
	{
		return false;
	}
	// Increment the ePDU count, dirrecty in the buffer
	buffer()[Frame::HEADER_SIZE + E_PDU_COUNT_OFFSET]++;

	// Copy the data from the SvPDU into the MPDU buffer
	*insert_ptr++ = svPdu.header();
	memcpy(insert_ptr, svPdu.buffer().data(), svPdu.size());

	// Increment insertion pointer to be ready for the next call!
	insert_ptr += svPdu.size();

	setLength(length() + svPdu.size() + 1);
	return true;
}

uint8_t Mpdu::ePduCount()
{
	return buffer()[Frame::HEADER_SIZE + E_PDU_COUNT_OFFSET];
}

