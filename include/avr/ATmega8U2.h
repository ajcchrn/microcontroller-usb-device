#ifndef AVR_ATMEGA8U2
#define AVR_ATMEGA8U2

#include <avr/core.h>
#include <avr/Port.h>
#include <avr/USART.h>

namespace AVR
{
	// I/O-ports
	Port &PortB = *reinterpret_cast<Port *>(0x23);
	Port &PortC = *reinterpret_cast<Port *>(0x26);
	Port &PortD = *reinterpret_cast<Port *>(0x29);

	// USART
	USART &USART1 = *reinterpret_cast<USART *>(0xC8);
}

#endif // AVR_ATMEGA8U2
