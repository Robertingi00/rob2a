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

#include "../../verkefni3/Forrit/controls.c"

const int threshold = 400;
const int TurnPower = 90;
string lineSensor = "";

const float dist = 50;//cm
int robot[2] = {1,0};
int karfa[2] = {0,3};

int glas_1[2] = {2,0};
int glas_2[2] = {0,1};
int glas_3[2] = {2,2};
int glas_4[2] = {2,4};
void ResetEncoders()
{
		nMotorEncoder[rightMotor] = 0;
		nMotorEncoder[leftMotor] = 0;
		SensorValue[leftEncoder] = 0;
		SensorValue[rightEncoder] = 0;
}

void ResetMotor()
{
    motor[rightMotor] = 0;
  	motor[leftMotor] = 0;
}


void TurnLeft(int deg)
{

		SensorType[in3] = sensorNone;
		wait1Msec(1000);
		SensorType[in3] = sensorGyro;
		wait1Msec(2000);

	  int rotate_degrees = deg * 10;

	  while(abs(SensorValue[in3]) < rotate_degrees)
	  {
	    motor[rightMotor] = TurnPower;
	    motor[leftMotor] = -(TurnPower);
	  }
	  motor[rightMotor] = -15;
	  motor[leftMotor] = 15;
	  wait1Msec(250);
}

void TurnRight(int deg)
{
    SensorType[in3] = sensorNone;
		wait1Msec(1000);
		SensorType[in3] = sensorGyro;
		wait1Msec(2000);

	  int rotate_degrees = deg * 10;

	  while(abs(SensorValue[in3]) < rotate_degrees)
	  {
	    motor[rightMotor] = -(TurnPower);
	    motor[leftMotor] = TurnPower;
	  }
	  motor[rightMotor] = 15;
	  motor[leftMotor] = -15;
	  wait1Msec(250);
}






float test(float cm){
  float tala = (cm / 33.0) * 360.0;
  return tala;
}

void drive()
{
	ResetEncoders();
	float wheel_degree = test(dist);
	float EncodersVales = 0;

	while(EncodersVales < wheel_degree){

		if(SensorValue(lineFollowerRIGHT) > threshold)
	  {
	    lineSensor = "R";
	    motor[leftMotor]  = 90;
		  motor[rightMotor] = 0;
	  }
		else if(SensorValue(lineFollowerCENTER) > threshold)
	  {
	    motor[leftMotor]  = 90;
	    motor[rightMotor] = 90;


	  }
		else if(SensorValue(lineFollowerLEFT) > threshold)
	  {
	    lineSensor = "L";
	    motor[leftMotor]  = 0;
		   	motor[rightMotor] = 90;
	  }else{

		  if(lineSensor == "R"){
		  		motor[leftMotor]  = 90;
		   		motor[rightMotor] = 0;
		  }
		  if(lineSensor == "L"){
		  		motor[leftMotor]  = 0;
		   		motor[rightMotor] = 90;
		  }
		}

		EncodersVales = (abs(SensorValue[rightEncoder]) + abs(SensorValue[leftEncoder]))/2;
	}
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

task stop()
{
	while(true){
		if (SensorValue(touchSensor) == 1){
			StopAllTasks();
		}
	}
}


task main()
{
	StartTask(stop);
	startTask(controls);
	find_object(robot, glas_1);TurnLeft(180);
	find_object(robot, karfa);TurnLeft(180);
	find_object(robot, glas_2);TurnLeft(180);
	find_object(robot, karfa);TurnLeft(180);
	find_object(robot, glas_4);TurnLeft(180);
	find_object(robot, karfa);TurnLeft(180);
	find_object(robot, glas_3);TurnLeft(180);
	find_object(robot, karfa);TurnLeft(180);

}
