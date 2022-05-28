#include "command_parser.h"


void command_parser(command_t command_received, i16 value)
{
    switch(command_received)
    {
        case COMMAND_1:
        {
            command_1_parser(value);
            break;
        }
        case COMMAND_2:
        {
            command_2_parser(value);
        }
        default:
        {
            break;
        }
    }
}


i16 convert_payload_to_i16(const u8 *payload)
{
    i16 value = (i16)payload[0] + (i16)(payload[1] << 16);
    return value;
}


void command_1_parser(i16 value)
{
    /* Command 1 implementation. */
}


void command_2_parser(i16 value)
{
    /* Command 1 implementation. */    
}
