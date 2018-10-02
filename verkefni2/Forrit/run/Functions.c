int const FullPower = 80;
int const MediumPower = 63.5;
float const WheelCircum = 32.673;
#define M_PI 3.14159265358979323846
int CmToDegree(int cm);

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
    SensorValue[rightEncoder] = 0;
  	SensorValue[leftEncoder] = 0;
}

void ResetMoror()
{
    motor[rightMotor] = 0;
  	motor[leftMotor] = 0;
}

void TurnRight(int deg)
{
    while(abs(SensorValue[leftEncoder]) < deg && abs(SensorValue[leftEncoder]) < deg)
    {
        motor[rightMotor] = FullPower;
        motor[leftMotor] = -(FullPower);
    }

    return;
}

void TurnLeft(int deg)
{
    ResetEncoders();
    while(abs(SensorValue[leftEncoder]) < (deg) && abs(SensorValue[leftEncoder]) < (deg)
    {
        motor[rightMotor] = -(FullPower);
        motor[leftMotor] = FullPower;
    }
}

float test(float cm){
  float tala = (cm / 33.0) * 360.0;
  return tala;
}
void DriveStraight(bool att)
{
    if (abs(SensorValue[rightEncoder]) + 100 > abs(SensorValue[leftEncoder])){
        if (att){
            motor[rightMotor] = (FullPower-20);
            motor[leftMotor] = FullPower;
        }else{
            motor[rightMotor] = -(FullPower-20);
            motor[leftMotor] = -(FullPower);
        }
    }else if(abs(SensorValue[leftEncoder]) + 100 > abs(SensorValue[rightEncoder])){
        if (att){
            motor[rightMotor] = FullPower;
            motor[leftMotor] = (FullPower-20);
        }else{

            motor[rightMotor] = -(FullPower);
            motor[leftMotor] = -(FullPower-20);
        }
        writeDebugStream("left motor er hradari \n",);
    }else{
        if (att){
            motor[rightMotor] = FullPower;
            motor[leftMotor] = FullPower;
        }else{
            motor[rightMotor] = -(FullPower);
            motor[leftMotor] = -(FullPower);
        }
    }
   writeDebugStream("left - encoder %d \n", abs(SensorValue[leftEncoder]));
   writeDebugStream("right - encoder %d \n", abs(SensorValue[rightEncoder]));
}


void MoveForward(float cm)
{
	ResetEncoders();
	float degree = test(cm);
	writeDebugStream("deggree %d \n", degree);

	while(abs(SensorValue[rightEncoder]) < degree){
		DriveStraight(true);
	}
	ResetMoror();
}

void MoveBackward(int cm)
{
	ResetEncoders();
	float degree = test(cm);
	while(abs(SensorValue[rightEncoder]) < degree){
			DriveStraight(false);
	}
	ResetMoror();
}

task stop()
{
	while(true){
		if (SensorValue(touchSensor) == 1){
			StopAllTasks();
		}
	}
}
