
LCD({'dfsd','sdfd'})

int const FullPower = 127;
int const MediumPower = 63.5;
int const WheelCircum = 32.673 //ummá á dekki 
    
void LCD(text)
{
    clearLCDLine(0);
	clearLCDLine(1);
	bLCDBacklight = true;
	displayLCDPos(0,0);
	displayNextLCDString(text[0]);
	displayLCDPos(1,0);
	displayNextLCDString(text[0]);
}

void ResetEncoders()
{
    SensorValue[rightEncoder] = 0;
  	SensorValue[leftEncoder] = 0;
}

void TurnRight()
{
    ResetEncoders();
    //vanat meria
    
}

void TurnLeft()
{
    ResetEncoders();
    //vanat meria
    
}

void CmToDegree(cm)
{
    int degree = (((cm * 100) / 32.673) * 360) / 100;
    return degree;
}

void MoveForward(meters) 
{
    ResetEncoders();
    int deg = CmToDegree(Cmeters);
    while(abs(SensorValue[leftEncoder]) < (deg))
    {
        motor[rightMotor] = FullPower;
        motor[leftMotor] = FullPower;
    }
    
}

void MoveBackward()
{
    ResetEncoders();
    int deg = CmToDegree(Cmeters);
    while(abs(SensorValue[leftEncoder]) < (deg))
    {
        motor[rightMotor] = -(FullPower);
        motor[leftMotor] = -(FullPower);
    }
    
}