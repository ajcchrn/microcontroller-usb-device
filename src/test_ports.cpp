#include <avr/ATmega8U2.h>
#include <stdint.h>

int main()
{
	AVR::PortD.set_data_direction(0x3);
	AVR::PortD.set_data_register(0x3);
}
