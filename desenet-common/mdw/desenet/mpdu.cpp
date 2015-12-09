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

Mpdu::Mpdu() : Frame(Frame::Mtu)
{
	//memset(buffer() + Frame::HEADER_SIZE, 0, 1);	// Set first field in payload to zero
    setDestination(GATEWAY_ADDRESS);



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


void Mpdu::add(uint8_t group, SvPDU& svPdu)
{
	uint8_t svPduHeader = ((group & 0x0F) << 3) | (svPdu.size() & 0x07);
	// Increment the ePDU count, dirrecty in the buffer
	buffer()[Frame::HEADER_SIZE + E_PDU_COUNT_OFFSET]++;

	// Copy the data from the SvPDU into the MPDU buffer
	*insert_ptr++ = svPduHeader;
	memcpy(insert_ptr, svPdu.buffer().data(), svPdu.size());

	// Increment insertion pointer to be ready for the next call!
	insert_ptr += svPdu.size();

	setLength(length() + svPdu.size() + 1);
}

