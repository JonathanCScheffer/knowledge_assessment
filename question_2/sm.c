#include "sm.h"
#include "sm_states.h"


void button_state_machine()
{
    button_state current_state = OFF;
    while (1)
    {
        switch (current_state)
        {
            case OFF:
            {
                current_state = button_state_off();
                break;
            }
            case ON:
            {
                current_state = button_state_on();
                break;
            }
            case PROTECTED:
            {
                current_state = button_state_protected();
                break;
            }
            default:
            {
                current_state = button_state_off();
                break;
            }
        }
    }
}
