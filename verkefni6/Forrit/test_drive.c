#include "../../program_connector/Functions.c"


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

const int dist = 50;//cm
int robot[2] = {0,1};
int object[2] = {4,2};

float test(float cm){
  float tala = (cm / 33.0) * 360.0;
  return tala;
}

void drive()
{
	ResetEncoders();
	float wheel_degree = test(dist);
	while(abs(SensorValue[rightEncoder]) < wheel_degree){

		 if(SensorValue(lineFollowerRIGHT) > threshold)
    {
      // counter-steer right:
      motor[leftMotor]  = 120;
      motor[rightMotor] = -10;
    }
    // CENTER sensor sees dark:
    if(SensorValue(lineFollowerCENTER) > threshold)
    {
      // go straight
      motor[leftMotor]  = 63;
      motor[rightMotor] = 63;
    }
    // LEFT sensor sees dark:
    if(SensorValue(lineFollowerLEFT) > threshold)
    {
      // counter-steer left:
      motor[leftMotor]  = -10;
      motor[rightMotor] = 100;
    }
    if(SensorValue(lineFollowerLEFT) < threshold && SensorValue(lineFollowerRIGHT) < threshold && SensorValue(lineFollowerCENTER) < threshold)
    {
    		motor[leftMotor]  = 0;
     	  motor[rightMotor] = 0;
     	  afram = false;
    }

	}
	motor[rightMotor] = -5;
  motor[leftMotor] = -5;
  wait1Msec(250);
	ResetMotor();
}



void find_object(int *robot, int *obj)
{
	int ferdX = obj[0] - robot[0];
	int ferdY = obj[1] - robot[1];
	int att; // 1 er ad fara nidur -1 er ad fara upp.
	// writeDebugStream("%d",ferdX);
	writeDebugStream("Robot Byrjar x = %d y = %d \n", robot[0],robot[1]);
	writeDebugStream("Obj Byrjar x = %d y = %d \n", obj[0],obj[1]);

	if(ferdY >= 0){
		att = 1;
	}else{
		att = -1;
	}

	if(ferdX != 1 || ferdX != -1){ // Ef robotinn er midju linunni sleppur hann thessum linum.
		if(ferdX == 2 || ferdX == -2){
			if(ferdX == 2){
				ferdX --;
				robot[0] ++;
				writeDebugStream("Robot fer i midjuna lina 17 \n");
				drive();
				switch(att){
					case 1:
						writeDebugStream("robot fer til haegri \n");
						TurnRight(90);
						break;
					case -1:
						writeDebugStream("Robot fer til vinstri \n");
						TurnLeft(90);
						break;
				}

			}else if(ferdX == -2){
				ferdX ++;
				robot[0] --;
				writeDebugStream("Robot fer i midjuna lina 21 \n");
				drive();
				switch(att){
					case 1:
						writeDebugStream("robot fer til vinstir \n");
						TurnLeft(90);
						break;
					case -1:
						writeDebugStream("robot fer til haegri \n");
						TurnRight(90);
						break;
				}

			}else{
				writeDebugStream("Villa  forritinu lina 22 \n");
			}

		}else if(ferdX == 0){
			if(robot[0] < 1){
				ferdX --;
				robot[0] ++;
				writeDebugStream("Robot fer i midjuna lina 30 \n");
				drive();
				switch(att){
					case 1:
						writeDebugStream("robot fer til haegri \n");
						TurnRight(90);
						break;
					case -1:
						writeDebugStream("robot fer til vinstir \n");
						TurnLeft(90);
						break;
				}

			}else if(robot[0] > 1){
				ferdX ++;
				robot[0] --;
				writeDebugStream("Robot fer i midjuna lina 34 \n");
				drive();
				switch(att){
					case 1:
						writeDebugStream("robot fer til vinstri \n");
						TurnLeft(90);
						break;
					case -1:
						writeDebugStream("robot fer til haegri \n");
						TurnRight(90);
						break;
				}

			}
			else{
				writeDebugStream("Villa  forritinu lina 36 \n");
			}
		}
	}



	writeDebugStream("Robot endar x = %d y = %d \n", robot[0],robot[1]);

	writeDebugStream("--------\n");
	for(int i = 0;i < abs(ferdY);i ++){
		switch(att){
				case 1:
					robot[1] ++;
					writeDebugStream("robot fer nidur\n");
					drive();
					break;
				case -1:
					robot[1] --;
					writeDebugStream("robot fer upp\n");
					drive();
					break;


		}

	}


	writeDebugStream("--------\n");


		switch(att){
				case 1:
					if(ferdX < 0){
						robot[0] --;
						writeDebugStream("Robot fer til haegri og svo afram line 113 \n");
						TurnRight(90);
						drive();
					}else if(ferdX > 0){
						robot[0] ++;
						writeDebugStream("Robot fer til vinstir og svo afram  lina 116 \n");
						TurnLeft(90);
						drive();
					}else{
						writeDebugStream("Villa i linu 79 \n");
					}
					break;
				case -1:
					if(ferdX < 0){
						robot[0] --;
						writeDebugStream("Robot fer til vinstir og svo afram line 124 \n");
						TurnLeft(90);
						drive();
					}else if(ferdX > 0){
						robot[0] ++;
						writeDebugStream("Robot fer til haegri og svo afram line 127 \n");
						TurnRight(90);
						drive();
					}else{
						writeDebugStream("Villa i linu 79 \n");
					}
					break;

		}

	writeDebugStream("Robot endar x = %d y = %d \n", robot[0],robot[1]);
}

task main()
{
	while(true){
		writeDebugStream("%d\n",object[1]);

	}
}
