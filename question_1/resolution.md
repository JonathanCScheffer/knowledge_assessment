# Electrolux knowledge assessment - Question 1

> Imagine a situation where you have a circuit able to activate and deactivate a purely resistive load with a microcontroller. It is required to control the load power over time depending on the situation and the power cannot be instantly changed from 0% to 100%. Explain in simple words a method to achieve such effect, looking at both hardware and firmware aspects of the system. If an inductive load is used instead of a resistive load, can the same triggering method be used or do special precautions need to be taken?

## Resolution

In order to control a purely resistive load with a microcontroller, a way o doing it is by using the PWM peripheral of the uC. This way, the load can be controlled by changing the duty cycle of the signal. In cases where the load drain a higher current than the supported by the PWM pin, a power supply circuit is needed and the PWM must control the load indirectly.
In cases where the load have inductive components, it is necessary to take care with the discharge of the inductor. If any precaution is taken, it may harm some sensitive iC's, earlier degradation of switches and unwanted EMI issues that could impact all the system. The precautions are to insert a free-wheel circuit to guarantee that by the time the switch is triggered, the inductor is discharged enough into a safe level. This circuit may differ on the implementation, considering the voltage levels of the system and the switching frequency, since the inductor must discharge faster in case of higher switching frequencies.
