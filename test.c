#pragma config(UART_Usage, UART1, uartVEXLCD, baudRate19200, IOPins, None, None)
#pragma config(UART_Usage, UART2, uartNotUsed, baudRate4800, IOPins, None, None)
#include "./program_connector/Functions.c"



task main()
{
	while(true){
			LCD('Taekniskolinn','2018')
	}
}
