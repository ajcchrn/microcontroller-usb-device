#include <avr/io.h>

int main()
{
	DDRD = 0x01;
	PORTD = 0x01;
}
