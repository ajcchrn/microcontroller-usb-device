#ifndef AVR_CORE_H
#define AVR_CORE_H

#include <stdint.h>

typedef uint8_t volatile dev_reg;

struct IO_PORT {
	dev_reg PIN;	// Input Pins Address
	dev_reg DDR;	// Data Direction Register
	dev_reg PORT;	// Data Register
};

static_assert(sizeof(IO_PORT) == 3 * sizeof(dev_reg),
	"IO_PORT was padded and doesn't line up");

#endif // AVR_CORE_H
