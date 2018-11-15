

int const FullPower = 65;
int const TurnPower = 90;


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
void DriveStraight(bool att)
{
    if (abs(SensorValue[rightEncoder]) + 20 < abs(SensorValue[leftEncoder])){
        if (att){
            motor[rightMotor] = FullPower+10;
            motor[leftMotor] = (FullPower-10);
        }else{
            motor[rightMotor] = -(FullPower+20);
            motor[leftMotor] = -(FullPower-20);

        }

    }else if(abs(SensorValue[leftEncoder]) + 20 < abs(SensorValue[rightEncoder])){
      if (att){
            motor[rightMotor] =(FullPower-10);
            motor[leftMotor] = (FullPower+10);
        }else{

            motor[rightMotor] = -(FullPower-20);
            motor[leftMotor] = -(FullPower+20);
        }

    }else{
        if (att){
            motor[rightMotor] = FullPower;
            motor[leftMotor] = FullPower;
        }else{
            motor[rightMotor] = -(FullPower);
            motor[leftMotor] = -(FullPower);
        }

    }

}


void MoveForward_cm(float cm)
{
	ResetEncoders();
	float wheel_degree = test(cm);
	while(abs(SensorValue[rightEncoder]) < wheel_degree){
		DriveStraight(true);
	}
	motor[rightMotor] = -5;
  motor[leftMotor] = -5;
  wait1Msec(250);
	ResetMotor();
}

void MoveBackward_cm(float cm)
{
	ResetEncoders();
	float wheel_degree = test(cm);
	while(abs(SensorValue[rightEncoder]) < wheel_degree){
			DriveStraight(false);
	}
	motor[rightMotor] = 5;
  motor[leftMotor] = 5;
  wait1Msec(250);
	ResetMotor();
}

task stop()
{
	while(true){
		if (SensorValue(touchSensor) == 1){
			StopAllTasks();
		}
	}
}
