#ifndef AVR_PORT_H
#define AVR_PORT_H

#include <avr/core.h>
#include <stdint.h>

namespace AVR
{
	class Port {
		public:
			void set_data_direction(uint8_t data_direction);
			void set_data_register(uint8_t data_value);
			uint8_t read_pin_register( );
		private:
			dev_reg PIN;	// Input Pins Address
			dev_reg DDR;	// Data Direction Register
			dev_reg PORT;	// Data Register
	};

	static_assert(sizeof(Port) == 3 * sizeof(dev_reg),
			"Size of Port class is wrong");
}

#endif // AVR_PORT_H
