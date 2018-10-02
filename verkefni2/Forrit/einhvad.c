int const FullPower = 80;
#define M_PI 3.14159265358979323846
int CmToDegree(int cm);
const float BASEDIST = 10.9;

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
}

/*
void TurnRight(int deg)
{
    while ((abs(SensorValue[leftEncoder]) < deg) && (abs(SensorValue[rightEncoder]) < deg))
    {
        motor[rightMotor] = FullPower;
        motor[leftMotor] = -(FullPower);
    }

    return;
}

void TurnLeft(int deg)
{
    ResetEncoders();
    while(abs(SensorValue[leftEncoder]) < (deg) && (abs(SensorValue[rightEncoder]) < (deg)
    {
        motor[rightMotor] = -(FullPower);
        motor[leftMotor] = FullPower;
    }
}
*/

float CmToDegree(int cm)
{
    float degree = cm * BASEDIST;
    return degree;
}
/*
void DriveStraight(bool att)
{
    if ((abs(nMotorEncoder[rightMotor])) > (abs(nMotorEncoder[leftMotor]))){
        if (att){
            motor[rightMotor] = (FullPower-20);
            motor[leftMotor] = FullPower;
        }else{
            motor[rightMotor] = -(FullPower-20);
            motor[leftMotor] = -(FullPower);
        }
    }
    if ((abs(nMotorEncoder[rightMotor])) < (abs(nMotorEncoder[leftMotor]))){
        if (att){
            motor[rightMotor] = FullPower;
            motor[leftMotor] = (FullPower-20);
        }else{
            motor[rightMotor] = -(FullPower);
            motor[leftMotor] = -(FullPower-20);
        }
    }
    if ((abs(nMotorEncoder[rightMotor])) == (abs(nMotorEncoder[leftMotor]))){
        if (att){
            motor[rightMotor] = FullPower;
            motor[leftMotor] = FullPower;
        }else{
            motor[rightMotor] = -(FullPower);
            motor[leftMotor] = -(FullPower);
        }
    }
}
*/

void MoveForward(int cm)
{
    ResetEncoders();
    float deg = CmToDegree(cm);
    while(abs(nMotorEncoder[rightMotor]) <= deg)
    {
        DriveStraight(true);
    }
    motor[rightMotor] = 0;
    motor[leftMotor] = 0;
}

void MoveBackward(int cm)
{
    ResetEncoders();
    float deg = CmToDegree(cm);
    while(abs(nMotorEncoder[rightMotor]) <= deg)
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
