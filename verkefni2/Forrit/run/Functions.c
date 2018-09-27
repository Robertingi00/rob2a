int const FullPower = 127;
int const MediumPower = 63.5;
int const WheelCircum = 32.673; //ummá á dekki
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

void TurnRight(int deg)
{
    while(abs(SensorValue[leftEncoder]) < (deg) && abs(SensorValue[leftEncoder]) < (deg)
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

double CmToDegree(int cm)
{
    double degree = (cm / 33) * 360;
    return degree;
}
void DriveStraight(bool att)
{
    if (SensorValue[rightEncoder] > (abs(SensorValue[leftEncoder]))){
        if (att){
            motor[rightMotor] = (FullPower-20);
            motor[leftMotor] = FullPower;
        }else{
            motor[rightMotor] = -(FullPower-20);
            motor[leftMotor] = -(FullPower);
        }
    }else if(SensorValue[rightEncoder] < (abs(SensorValue[leftEncoder]))){
        if (att){
            motor[rightMotor] = FullPower;
            motor[leftMotor] = (FullPower-20);
        }else{

            motor[rightMotor] = -(FullPower);
            motor[leftMotor] = -(FullPower-20);
        }
    }else if(SensorValue[rightEncoder] == (abs(SensorValue[leftEncoder]))){
        if (att){
            motor[rightMotor] = FullPower;
            motor[leftMotor] = FullPower;
        }else{
            motor[rightMotor] = -(FullPower);
            motor[leftMotor] = -(FullPower);
        }
    }
}

void MoveForward(int cm)
{
    ResetEncoders();
    double deg = CmToDegree(cm);
    while(abs(SensorValue[rightEncoder]) < (deg))
    {
        DriveStraight(true);
    }
    motor[rightMotor] = 0;
    motor[leftMotor] = 0;
}

void MoveBackward(int cm)
{
    ResetEncoders();
    double deg = CmToDegree(cm);
    while(abs(SensorValue[rightEncoder]) < (deg))
    {
        DriveStraight(false);//false seigir forritinu ad hann se ad fara aftur a bak
    }
    motor[rightMotor] = 0;
    motor[leftMotor] = 0;
}

task stop()
{
	while(true){
		if (SensorValue(touchSensor) == 1){
			StopAllTasks();
		}
	}
}
