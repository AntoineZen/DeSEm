#include "desenet/sensor/net.h"
#include "abstractapplication.h"

using desenet::sensor::AbstractApplication;

/*********************************************************************************************************
* TODO: Implement the protected methods of the AbstractApplication class here. From these you have to    *
* call the different methods on your DESENET Controller Entity implementation...                         *
*********************************************************************************************************/

// Default implementations.

void AbstractApplication::svSyncRequest()
{
	Net::instance().entity().svSyncRequest(this);
}

bool AbstractApplication::svPublishRequest(SvGroup group)
{
	return Net::instance().entity().svPublishRequest(this, group);
}

/**
 * @brief Default callback method for syncs
 */
void AbstractApplication::svSyncIndication(desenet::NetworkTime)
{
}

/**
 * @brief Default callback method for SV publishes
 */
SharedByteBuffer::sizeType AbstractApplication::svPublishIndication(SvGroup, SharedByteBuffer &)
{
	return 0;
}

void AbstractApplication::evPublishRequest(EvId id, const SharedByteBuffer & evData)
{
}
