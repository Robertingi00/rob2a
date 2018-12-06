#pragma config(UART_Usage, UART1, uartVEXLCD, baudRate19200, IOPins, None, None)
#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in2,    lineFollowerCENTER, sensorLineFollower)
#pragma config(Sensor, in4,    lightSensor,    sensorReflection)
#pragma config(Sensor, in5,    ArmeEncoder,    sensorPotentiometer)
#pragma config(Sensor, in6,    potentiometerChoice, sensorPotentiometer)
#pragma config(Sensor, in7,    lineFollowerRIGHT, sensorLineFollower)
#pragma config(Sensor, in8,    lineFollowerLEFT, sensorLineFollower)
#pragma config(Sensor, dgtl1,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl8,  sonar,          sensorSONAR_cm)
#pragma config(Sensor, dgtl12, touchSensor,    sensorTouch)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_2,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Motor,  port1,           rightMotor,    tmotorVex393HighSpeed, openLoop, encoder, encoderPort, I2C_2, 1692728)
#pragma config(Motor,  port4,           armMotor,      tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port5,           handMotor,     tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port10,          leftMotor,     tmotorVex393HighSpeed, openLoop, reversed, encoder, encoderPort, I2C_1, 1692728)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "./verkefni_6.c";

string obj[4] = {"Bolti1","Bolti2","Bolti3","Bolti4"};
int index = 0;
string hvad = "Hvad viltu";

void LCD(string text_1, string text_2)
{
  clearLCDLine(0);
	clearLCDLine(1);
	bLCDBacklight = true;
	displayLCDPos(0,0);
	displayNextLCDString(text_1);
	displayLCDPos(1,0);
	displayNextLCDString(text_2);
}



task main()
{
	StartTask(stop);

	motor[handMotor] = 40;
	motor[armMotor] = -40;
	wait1Msec(2000);
	motor[handMotor] = 0;
	motor[armMotor] = 0;
	StartTask(stop);
	while(true){
		if(SensorValue[potentiometerChoice] < 15){
				writeDebugStream("Glas 1\n");
				index = 0;
		}
		else if(SensorValue[potentiometerChoice] > 15 && SensorValue[potentiometerChoice] < 30){
				writeDebugStream("Glas 2\n");
				index = 1;
		}
		else if(SensorValue[potentiometerChoice] > 45 && SensorValue[potentiometerChoice] < 60){
				writeDebugStream("Glas 3\n");
				index = 2;
		}
		else if(SensorValue[potentiometerChoice] > 60){
				writeDebugStream("Glas 4\n");
				index = 3;
		}

		if(nLCDButtons == 2){
			switch(index){
				case 0:
					writeDebugStream("Glas 1\n");
					find_object(robot, glas_1);armur();TurnLeft(180);
					break;
				case 1:
					writeDebugStream("Glas 2\n");
					find_object(robot, glas_2);armur();TurnLeft(180);
					break;

				case 2:
					writeDebugStream("Glas 3\n");
					find_object(robot, glas_3);armur();TurnLeft(180);
					break;

				case 3:
					writeDebugStream("Glas 4\n");
					find_object(robot, glas_4);armur();TurnLeft(180);
					break;
			}
			find_object(robot, karfa);armur();TurnLeft(180);

		}
		LCD(hvad,obj[index]);
		wait1Msec(250);
	}
}
