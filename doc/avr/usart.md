# USART
The header `include/avr/usart.h` contains declarations for the USART related functions implemented by this library.

## Initialization
The USART can be initialized with the function `usart_init(unsigned int)` where the argument is the baud rate.

## Functionality 
The functionality implemented in this library is described below.

### Put char
The `usart_putchar(char)` function will transmitt a single character. This function is blocking.
