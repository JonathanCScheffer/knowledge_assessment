#include "types.h"

#define FRAME_MAX_LEN 8     /* Maximum number of bytes per frame. */
#define FRAME_POS_STX 0     /* Frame STX position. */
#define FRAME_POS_CMD 2     /* Frame command position.  */
#define FRAME_POS_DATA 3    /* Frame data start position. */
#define FRAME_POS_CRC 6     /* Frame CRC. */
#define FRAME_POS_ETX 7     /* Frame ETX position. */

#define FRAME_STX 0x61      /* char 'a'. Represents a frame STX. */
#define FRAME_ETX 0x7a      /* char 'z'. Represents a frame ETX. */


typedef enum
{
    COMMAND_1 = 0x01,
    COMMAND_2 = 0x02,
} command_t;


void command_parser(command_t command, i16 value);
i16 convert_payload_to_i16(const u8 *payload);
void command_1_parser(i16 value);
void command_2_parser(i16 value);
