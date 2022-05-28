/**
 * @file arduino.h
 * @brief Header file to mock Arduino functions.
 */
#include <stdbool.h>

#define OUTPUT 0
#define INPUT 1


void delay(unsigned int milliseconds);
bool digitalRead(int pin);
void pinMode(int pin, int mode);
