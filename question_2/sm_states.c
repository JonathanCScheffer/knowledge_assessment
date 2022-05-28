#include "arduino.h"
#include "button.h"
#include "sm_states.h"


button_state button_state_off(void)
{
    button_state eNextState;
    if(is_button_pressed()==false)
    {
        eNextState = OFF;
    }
    else
    {
        eNextState = ON;
    }
    return eNextState;
}

button_state button_state_on(void)
{
    button_state eNextState;
    if(is_button_pressed()==true)
    {
        eNextState = ON;
    }
    else
    {
        eNextState = PROTECTED;
    }
    return eNextState;
}

button_state button_state_protected(void)
{
    delay(10000);
    return OFF;
}
