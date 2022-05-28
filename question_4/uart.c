#include <stdbool.h>
#include "command_parser.h"
#include "crc.h"
#include "types.h"
#include "uart.h"


u8 uart_rx_buffer[FRAME_MAX_LEN];


void uart_interrupt_handler(void)
{
    u8 byte_rx;
    int byte_rx_index = 0;

    if(UARTIntStatus(UART_PORT, true) == UART_INT_RX)
    {
        UARTIntClear(UART_PORT, UART_INT_RX);

        byte_rx = UARTCharGet(UART_PORT);
        byte_rx_index++;

        if (byte_rx == FRAME_STX)
        {
            while (byte_rx_index < FRAME_MAX_LEN)
            {
                uart_rx_buffer[byte_rx_index++] = UARTCharGet(UART_PORT);
            }

            if ((uart_rx_buffer[FRAME_POS_ETX] == FRAME_ETX) && check_crc8(uart_rx_buffer, FRAME_MAX_LEN, FRAME_POS_CRC))
            {
                command_t command_id = (command_t)uart_rx_buffer[FRAME_POS_CMD];
                i16 value = convert_payload_to_i16(&uart_rx_buffer[FRAME_POS_DATA]);
                command_parser(command_id, value);
            }
        }

        while(byte_rx_index)
        {
            uart_rx_buffer[--byte_rx_index] = 0;
        }
    }
}


void uart_interrupt_enable(void)
{
    UARTIntRegister(UART_PORT, uart_interrupt_handler);
}
