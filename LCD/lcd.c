#pragma config(UART_Usage, UART1, uartVEXLCD, baudRate19200, IOPins, None, None)
#pragma config(UART_Usage, UART2, uartNotUsed, baudRate4800, IOPins, None, None)
#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in4,    lightSensor,    sensorReflection)
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
#pragma config(Sensor, in2,    lineFollowerCENTER,  sensorLineFollower)
#pragma config(Sensor, in8,    lineFollowerLEFT,    sensorLineFollower)

/*----------------------------------------------------------------------------------------------------*\
|*                                         - Bip  -                                                   *|
|*                                      ROBOTC on VEX 2.0 CORTEX                                      *|
|*                                                                                                    *|
|*  File sem runnar öll verkefnin, þú velur verkefni sem þú vilt runna.    			      *|
\*-----------------------------------------------------------------------------------------------4246-*/
#include "../program_connector/Functions.c"
#include "../verkefni2/Forrit/verkefni_2.c"
#include "../verkefni3/Forrit/controls.c"
#include "../verkefni4/Forrit/verkefni_4.c"
#include "../verkefni5/Forrit/verkefni_5.c"

string lcd_array[] = {"verkefni 2","Hluti 1","Hluti 2","Hluti 3","verkefni 4","verkefni 5","verkefni 6","verkefni 7","----------------------"};

int index = 0;
int index2 = 1;

bool afram;



//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task lcd()
{
	while(true){
		if(nLCDButtons == 4){
			if(index >= 2 && index < 7){
				index ++;
			}else if(index < 7){
				index = 0;
				index2 ++;
				if(index2 > 3){
					index = 4;
					index2 = 8;
				}
			}

		}

		if(nLCDButtons == 1){
			if(index > 4){
				index --;
				index2 = 8;
			}else if(index >= 0 && index2 > 1){
				if(index2 == 8){index2 = 4;};
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
					StopTask(controls);
					afram = false;
					switch(index){
						case 0:
							switch(index2){
								case 1:
									hluti_1();
									break;
								case 2:
									hluti_2();
									break;
								case 3:
									hluti_3();
									break;

								break;
							}
						case 4:
							if(index != 0){
									verkefni_4();
							}
							break;
						case 5:
							if(index != 0){
									verkefni_5();
							}
							break;
					}
					StartTask(controls);
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
	StartTask(controls);
	while(true){

	}
}
