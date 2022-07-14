#include <stdint.h>
#include <avr/io.h>
#include <avr/usart.h>

#define BAUD_RATE 9600UL

void usart_init(void)
{
	uint16_t UBRR = F_OSC / (16ul*BAUD_RATE) - 1;

	// Set baud rate registers
	UBRR1L = (uint8_t)(0x00FF & UBRR);
	UBRR1H = (uint8_t)((0xFF00 & UBRR) >> 8);

	// Enable receiver and transmitter
	UCSR1B = 0x18; // RXEN | TXEN

	// Set frame format
	UCSR1C = 0x06; // 8-N-1

	// Clear A
	UCSR1A = 0x00; // ~U2X
	UCSR1D = 0x00; // ~CTSEN | ~RTSEN
}

void usart_putchar(char letter)
{
	while ( !(UCSR1A & 0x20) ); // Block until ready

	// Writing to UDR transmitts a byte
	UDR1 = letter;
}
