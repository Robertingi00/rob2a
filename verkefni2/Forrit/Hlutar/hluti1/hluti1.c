#pragma config(Motor,  port2,           rightMotor,    tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port3,           leftMotor,     tmotorNormal, openLoop)
#pragma config(UART_Usage, UART1, uartVEXLCD, baudRate19200, IOPins, None, None)
#pragma config(UART_Usage, UART2, uartNotUsed, baudRate4800, IOPins, None, None)

//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*----------------------------------------------------------------------------------------------------*\
|*                                         - Bip  -                                         	      *|
|*                                      ROBOTC on VEX 2.0 CORTEX                                      *|
|*                                                                                                    *|
|*   Í hluta 1 erum við að keyra áfram 50cm og 50cm til baka og eftir hverja umferð eykst             *|
|*   vegalengdin alltaf um 50cm. Þannig næsta umferð verður 1m áfram og 1m til baka.                  *|
|*   Við erum að gera þetta eftir tíma.                                                               *|
\*-----------------------------------------------------------------------------------------------4246-*/

// 72cm a 2sec
// 50cm a 1,388888888889
// 36cm a 1sek

int const timi = 1.388888889; //lengdi til ad fara halfan meter
//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
void hluti_1()
{
	for (int i = 1; i <= 5;i++){
		motor[rightMotor] = 127;
		motor[leftMotor]  = 127;
		wait1Msec((timi*i)*1000);

		motor[rightMotor] = 0;
		motor[leftMotor]  = 0;
		wait1Msec(1000);

		motor[rightMotor] = -127;
		motor[leftMotor]  = -127;
		wait1Msec((timi*i)*1000);
	}
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
