#include "arduino.h"
#include "button.h"


void setup_button()
{
    pinMode(BUTTON_PIN, INPUT);
}

bool is_button_pressed()
{
    return digitalRead(BUTTON_PIN);
}
