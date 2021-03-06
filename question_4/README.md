# Electrolux knowledge assessment - Question 4

> Imagine that you have a microcontroller that communicates to a generic system that may consist of several other boards via UART. How do you guarantee each message you send is delivered correctly? Now imagine that you receive a message and an interruption is triggered every time a new information is received. Inside every message you have a different command, and for every command you have different payloads, receiving positive and negative values. Implement the interrupt and the parser functions in a generic way using the C language and share this code through a public repository on GitHub. Low-level methods can be abstracted. If you prefer, use frameworks like Arduino, ESP32 or even other market platforms in this low-level code abstraction.

## Resolution

Considering that a UART communication may have EMI interferences, a good practice is to always setup the more suitable link configurations such as parity, baud rate and data bits, according to the performance of the connected devices and converters. After ensuring that the communication link is rightly set, one of the most common error detection algorithms is the _Cyclic Redundancy Check_, also known as CRC, which is a low level measure to improve the hit rate. The success rate of the communication link may also be improved on the application level of the protocol, however, these implementations could cost a lot of overhead for each transferred protocol data unit, which also requires a more sophisticated hardware and firmware implementations.

## Build instructions with gcc

```bash
gcc *.c
```
