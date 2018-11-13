#pragma config(UART_Usage, UART1, uartVEXLCD, baudRate19200, IOPins, None, None)
#pragma config(UART_Usage, UART2, uartNotUsed, baudRate4800, IOPins, None, None)
#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, dgtl1,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl12, touchSensor,    sensorTouch)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_2,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Motor,  port1,           rightMotor,    tmotorVex393HighSpeed, openLoop, encoder, encoderPort, I2C_2, 1692728)
#pragma config(Motor,  port10,          leftMotor,     tmotorVex393HighSpeed, openLoop, reversed, encoder, encoderPort, I2C_1, 1692728)
#pragma config(Motor,  port4,           armMotor,      tmotorNormal, openLoop)

/*----------------------------------------------------------------------------------------------------*\
|*                                            - Bip  -                                                *|
|*                                      ROBOTC on VEX 2.0 CORTEX                                      *|
|*                                                                                                    *|
|*  Í hluta 3 áttum við að láta vélmennið keyra eftir tilbúna braut.                                  *|
|*  Við notuðum föll sem við bjuggum til til að keyra áfram ákveðna vegalegnd og                      *|
|*  beygja ákveðnar gráður.                                                                           *|
\*-----------------------------------------------------------------------------------------------4246-*/


//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
#include "../../../../program_connector/Functions.c"

void hluti_3(){
	StartTask(stop);
	MoveForward_cm(50);
	wait1Msec(1000);
	TurnLeft(90.0);

	wait1Msec(1000);
	MoveForward_cm(50);
	wait1Msec(1000);
	TurnRight(90.0);

	wait1Msec(1000);
	MoveForward_cm(50);
	wait1Msec(1000);
	TurnRight(90.0);

	wait1Msec(1000);
	MoveForward_cm(50);
	wait1Msec(1000);

	MoveForward_cm(50);
	wait1Msec(1000);
	TurnLeft(90.0);
}

task main()
{
	hluti_3();
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++  +++++++++++++++++++++++++++++++++++++++
