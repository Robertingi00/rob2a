#pragma config(UART_Usage, UART1, uartVEXLCD, baudRate19200, IOPins, None, None)
#pragma config(UART_Usage, UART2, uartNotUsed, baudRate4800, IOPins, None, None)
#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, dgtl1,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl12, touchSensor,    sensorTouch)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_2,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Motor,  port1,           rightMotor,    tmotorVex393HighSpeed, openLoop, encoder, encoderPort, I2C_2)
#pragma config(Motor,  port10,          leftMotor,     tmotorVex393HighSpeed, openLoop, reversed, encoder, encoderPort, I2C_1)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "../../test/kypler.c"
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*----------------------------------------------------------------------------------------------------*\
|*                                         - Bip  -                                         *|
|*                                      ROBOTC on VEX 2.0 CORTEX                                      *|
|*                                                                                                    *|
|*  This program instructs your robot to move forward at full power for three seconds.  There is a    *|
|*  two second pause at the beginning of the program.                                                 *|
|*                                                                                                    *|
|*                                        ROBOT CONFIGURATION                                         *|
|*    NOTES:                                                                                          *|
|*    1)  Reversing 'rightMotor' (port 2) in the "Motors and Sensors Setup" is needed with the        *|
|*        "Squarebot" mode, but may not be needed for all robot configurations.                       *|
|*    2)  Power levels that can be assigned to a motor port range from -127 (full reverse) to         *|
|*        127 (full forward).                                                                         *|
|*                                                                                                    *|
|*    MOTORS & SENSORS:                                                                               *|
|*    [I/O Port]          [Name]              [Type]                [Description]                     *|
|*    Motor Port 2        rightMotor          VEX 3-wire module     Right side motor                  *|
|*    Motor Port 3        leftMotor           VEX 3-wire module     Left side motor                   *|
\*-----------------------------------------------------------------------------------------------4246-*/
// Thvermal = 10,3

// ummal deks 33cm
// 33 = 100 %
// 50 = 151,5%
// 360 * 1,515 = 545,4

int const HalfMetar= 545.4; //gradur sem encoderinn fer
//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++

task main()
{


	MoveForwardNew(50);
	MoveBackwardNew(50);




	/*
	StartTask(stop);
	string set_1 = "sdfdsd1";
	string set_2 = "sdfsdf2";
	LCD(set_1,set_2);
	for (int i = 1;i <= 5; i++){
			MoveForward(50*i);
			wait1Msec(2000);
			MoveBackward(50*i);
			wait1Msec(2000);

	}

	clearLCDLine(0);
	clearLCDLine(1);
	bLCDBacklight = true;
	displayLCDPos(0,0);
	displayNextLCDString("Verkefni 2");
	displayLCDPos(1,0);
	displayNextLCDString("Hluti 2");
	wait1Msec(5000)
	SensorValue[rightEncoder] = 0;
  SensorValue[leftEncoder] = 0;

  for(int i = 1;i <= 5; i++){
  	SensorValue[rightEncoder] = 0;
  	SensorValue[leftEncoder] = 0;
  	while(abs(SensorValue[leftEncoder]) < (HalfMetar*i))
  	{
	    motor[rightMotor] = 127;
	    motor[leftMotor] = 127;
  	}
  	SensorValue[rightEncoder] = 0;
  	SensorValue[leftEncoder] = 0;
  	wait1Msec(1000);
  	motor[rightMotor] = 0;
	  motor[leftMotor] = 0;
  	while(abs(SensorValue[leftEncoder]) < (HalfMetar*i))
  	{
	    motor[rightMotor] = -127;
	    motor[leftMotor] = -127;

  	}

  }
	*/

}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
