
LCD({'dfsd','sdfd'})

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