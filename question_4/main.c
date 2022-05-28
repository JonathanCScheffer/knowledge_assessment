#include "uart.h"


void main(void)
{
    uart_interrupt_enable();
    while(1)
    {
        /* All logic occurs from UART interrupt (uart_interrupt_handler) */
    }
}
