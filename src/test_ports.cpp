#include <avr/ATmega8U2.h>
#include <stdint.h>

int main()
{
	AVR::PortD.set_data_direction(0x2);
	AVR::PortD.set_data_register(0x2);

	AVR::USART1.init(9600ul);
	AVR::USART1.write('H');
	AVR::USART1.write('e');
	AVR::USART1.write('j');
	AVR::USART1.write('!');
	AVR::USART1.write('\r');
}
