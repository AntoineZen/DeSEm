#include <assert.h>
#include <random>
#include "platform-config.h"
#include "trace/trace.h"
#include "xf/xf.h"
#include "accelerometer.h"

namespace board {

bool Accelerometer::initialize()
{
	return true;
}

// static
void Accelerometer::getAccelerationValues(int16_t & x, int16_t & y, int16_t & z)
{
	x = qrand() % 4096 - 2048;
	y = qrand() % 4096 - 2048;
	z = qrand() % 4096 - 2048;
}

} // namespace board
