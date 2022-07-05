#include <avr/ATmega8U2.h>
#include <cstdint>

int main()
{
	std::uint8_t bit_value = 0x01;

	AVR::PortD.set_data_direction(bit_value);
	AVR::PortD.set_data_register(bit_value);

	AVR::USART1.init(9600ul);
	AVR::USART1.write('H');
	AVR::USART1.write('e');
	AVR::USART1.write('j');
	AVR::USART1.write('!');
	AVR::USART1.write('\r');
}
