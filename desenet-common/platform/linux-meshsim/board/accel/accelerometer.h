#pragma once

#include <stdint.h>

namespace board {

/**
 * @brief Class interfacing the real accelerometer hardware.
 */
class Accelerometer
{
public:
	Accelerometer() {}
	~Accelerometer() {}

	bool initialize();
	static void getAccelerationValues(int16_t & x, int16_t & y, int16_t & z);

protected:
	inline static bool isInitialized() { return true; }
};

} // namespace board
