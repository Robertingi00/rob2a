
int const FullPower = 65;
float const Dd_left = 2.825;
float const Dd_right = 2.675;
int const TurnPower = 100;

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

void TurnRight90()
{
		ResetEncoders();
   	float test_degree = (Dd_right * 90);
    while(abs(SensorValue[leftEncoder]) < test_degree)
    {
        motor[rightMotor] = -(TurnPower);
        motor[leftMotor] = TurnPower;
    }
    ResetMotor();
}

void TurnLeft90()
{
    ResetEncoders();
   	float test_degree = (Dd_left * 90);
    while(abs(SensorValue[leftEncoder]) < test_degree)
    {
        motor[rightMotor] = TurnPower;
        motor[leftMotor] = -(TurnPower);
    }
    ResetMotor();
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
	float degree = test(cm);
	while(abs(SensorValue[rightEncoder]) < degree){
		DriveStraight(true);
	}
	ResetMotor();
}

void MoveBackward_cm(float cm)
{
	ResetEncoders();
	float degree = test(cm);
	while(abs(SensorValue[rightEncoder]) < degree){
			DriveStraight(false);
	}
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
