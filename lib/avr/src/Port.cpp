#include <avr/Port.h>

namespace AVR
{
	void Port::set_data_direction(uint8_t data_direction)
	{
		DDR = data_direction;
	}

	void Port::set_data_register(uint8_t data_value)
	{
		PORT = data_value;
	}

	uint8_t Port::read_pin_register( )
	{
		return PIN;
	}
}
