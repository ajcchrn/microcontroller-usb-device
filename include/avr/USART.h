#ifndef AVR_USART_H
#define AVR_USART_H

#include <avr/core.h>
#include <stdint.h>

namespace AVR
{
	class USART {
		public:
			void init(unsigned long baud_rate,
				bool double_speed = false);
			void write(unsigned char letter);
		private:
		// Device registers
			dev_reg UCSRA;	// USART Control and Status Register A
			dev_reg UCSRB;	// Reg. B
			dev_reg UCSRC;	// Reg. C
			dev_reg UCSRD;	// Reg. D 
			dev_reg UBRRL;	// Baud Rate Register Low Byte
			dev_reg UBRRH;	// Baud Rate Register High Byte
			dev_reg UDR;	// I/O Data Register
	};

	static_assert(sizeof(USART) == 7 * sizeof(dev_reg),
			"Size of USART class is wrong");
}

#endif // AVR_USART_H
