#ifndef AVR_ATMEGA8U2
#define AVR_ATMEGA8U2

#include "core.h"

// I/O-ports
IO_PORT &port_b = *reinterpret_cast<IO_PORT *>(0x23);
IO_PORT &port_c = *reinterpret_cast<IO_PORT *>(0x26);
IO_PORT &port_d = *reinterpret_cast<IO_PORT *>(0x29);

#endif // AVR_ATMEGA8U2
