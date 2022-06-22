#include <avr/USART.h>
#include <stdint.h>

namespace AVR
{
	void USART::init(unsigned long baud_rate, bool double_speed)
	{
		// Calculate baud rate register setting
		uint16_t UBRR = 0;
		if (double_speed == false) {
			UBRR = F_OSC / (16ul*baud_rate) - 1ul;
		} else {
			UBRR = F_OSC / (8ul*baud_rate) - 1ul;
		}

		// Set baud rate registers
		UBRRL = static_cast<uint8_t>(0x00FF & UBRR);
		UBRRH = static_cast<uint8_t>((0xFF00 & UBRR) >> 8);

		// Enable receiver and transmitter
		UCSRB = 0x18; // RXEN | TXEN

		// Set frame format
		UCSRC = 0x06; // 8-N-1

		// Clear A
		UCSRA = 0x00; // ~U2X
		UCSRD = 0x00; // ~CTSEN | ~RTSEN
	}

	void USART::write(unsigned char letter)
	{
		while ( !(UCSRA & 0x20) ); // Block until ready

		// Writing to UDR transmitts a byte
		UDR = letter;
	}
}
