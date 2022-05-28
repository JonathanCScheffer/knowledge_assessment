
#define UARTA1_BASE 0x00000000
#define UART_INT_RX 0x00000001

char UARTCharGet(int);
int UARTIntStatus(int, int);
void UARTIntClear(int, int);
void UARTIntRegister(int, void*);
