#include <avr/atmega8u2.h>
#include <stdint.h>

int main()
{
	AVR::port_d.set_data_direction(0x2);
	AVR::port_d.set_data_register(0x2);
}
