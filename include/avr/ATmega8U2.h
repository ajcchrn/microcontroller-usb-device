#ifndef AVR_ATMEGA8U2
#define AVR_ATMEGA8U2

#include <avr/core.h>
#include <avr/Port.h>

namespace AVR
{
	// I/O-ports
	Port &PortB = *reinterpret_cast<Port *>(0x23);
	Port &PortC = *reinterpret_cast<Port *>(0x26);
	Port &PortD = *reinterpret_cast<Port *>(0x29);
}

#endif // AVR_ATMEGA8U2
