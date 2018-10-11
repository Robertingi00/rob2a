#pragma config(UART_Usage, UART1, uartVEXLCD, baudRate19200, IOPins, None, None)
#pragma config(UART_Usage, UART2, uartNotUsed, baudRate4800, IOPins, None, None)
#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in2,    lightSensor,    sensorReflection)
#pragma config(Sensor, in5,    ArmeEncoder,    sensorPotentiometer)
#pragma config(Sensor, dgtl1,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl8,  sonar,          sensorSONAR_cm)
#pragma config(Sensor, dgtl12, touchSensor,    sensorTouch)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_2,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Motor,  port1,           rightMotor,    tmotorVex393HighSpeed, openLoop, encoder, encoderPort, I2C_2, 1692728)
#pragma config(Motor,  port10,          leftMotor,     tmotorVex393HighSpeed, openLoop, reversed, encoder, encoderPort, I2C_1, 1692728)
#pragma config(Motor,  port4,           armMotor,      tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port5,           handMotor,     tmotorServoContinuousRotation, openLoop)
#pragma config(Sensor, in7,    lineFollowerRIGHT,   sensorLineFollower)
#pragma config(Sensor, in1,    lineFollowerCENTER,  sensorLineFollower)
#pragma config(Sensor, in8,    lineFollowerLEFT,    sensorLineFollower)
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
#include "../program_connector/Functions.c"
#include "../verkefni2/Forrit/verkefni_2.c"
//#include "../verkefni3/Forrit/controls.c"
#include "../verkefni4/Forrit/verkefni_4.c"
#include "../verkefni5/Forrit/verkefni_5.c"

string lcd_array[] = {"verkefni 2","Hluti 1","Hluti 2","Hluti 3","verkefni 3","verkefni 4","verkefni 5","verkefni 6","verkefni 7","----------------------"};

int index = 0;
int index2 = 1;

bool afram;


//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task lcd()
{
	while(true){
		if(nLCDButtons == 4){
			if(index >= 2 && index < 8){
				index ++;
			}else if(index < 8){
				index = 0;
				index2 ++;
				if(index2 > 3){
					index = 4;
					index2 = 9;
				}
			}

		}

		if(nLCDButtons == 1){
			if(index > 4){
				index --;
				index2 = 9;
			}else if(index >= 0 && index2 > 1){
				if(index2 == 9){index2 = 4;};
				index = 0;
				index2 --;

			}

		}
		if(nLCDButtons == 2){
			afram = true;
			while(afram)
			{
				clearLCDLine(0);
				clearLCDLine(1);
				displayLCDPos(0,6);
				displayNextLCDString("Run");
				displayLCDPos(1,2);
				displayNextLCDString("Yes");
				displayLCDPos(1,12);
				displayNextLCDString("No");
				wait1Msec(250);
				if(nLCDButtons == 4){
					afram = false;
				}
				if(nLCDButtons == 1){
					switch(index){
						case  5:
							verkefni_4();
							break;
						case 6:
							verkefni_5();
							wait1Msec(2000);
							TurnLeft90();
							break;

					}
				}
			}
		}

		LCD(lcd_array[index],lcd_array[index2]);
		wait1Msec(250);
	}
}
task main()
{
	StartTask(stop);
	StartTask(lcd);
	while(true){

	}
}
