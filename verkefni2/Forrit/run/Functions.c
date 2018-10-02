int const FullPower = 63;

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

void TurnRight(int deg)
{
		ResetEncoders()
    while(abs(SensorValue[leftEncoder]) < deg && abs(SensorValue[leftEncoder]) < deg)
    {
        motor[rightMotor] = FullPower;
        motor[leftMotor] = -(FullPower);
    }

    return;
}

void TurnLeft(float deg)
{
    ResetEncoders();
    float test_tala = 35.0 / 10.6;
   	float test_degree = (test_tala * deg);
    while(abs(SensorValue[leftEncoder]) < (test_degree) && abs(SensorValue[rightEncoder]) < (test_degree))
    {
        motor[rightMotor] = -(80);
        motor[leftMotor] = 80;
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
            writeDebugStream("-------------------Back-------------\n");

        }
        writeDebugStream("--------------------------------------------------\n");
        writeDebugStream("right motor er hradari \n",);
        writeDebugStream("left - encoder %d \n", abs(SensorValue[leftEncoder]));
   			writeDebugStream("right - encoder %d \n", abs(SensorValue[rightEncoder]));
   			writeDebugStream("--------------------------------------------------\n");
    }else if(abs(SensorValue[leftEncoder]) + 20 < abs(SensorValue[rightEncoder])){
      if (att){
            motor[rightMotor] =(FullPower-10);
            motor[leftMotor] = (FullPower+10);
        }else{

            motor[rightMotor] = -(FullPower-20);
            motor[leftMotor] = -(FullPower+20);
            writeDebugStream("-------------------Back-------------\n");
        }
        writeDebugStream("--------------------------------------------------\n");
        writeDebugStream("left motor er hradari \n",);
        writeDebugStream("left - encoder %d \n", abs(SensorValue[leftEncoder]));
   			writeDebugStream("right - encoder %d \n", abs(SensorValue[rightEncoder]));
   			writeDebugStream("--------------------------------------------------\n");
    }else{
        if (att){
            motor[rightMotor] = FullPower;
            motor[leftMotor] = FullPower;
        }else{
            motor[rightMotor] = -(FullPower);
            motor[leftMotor] = -(FullPower);
            writeDebugStream("-------------------Back-------------\n");
        }
       	writeDebugStream("--------------------------------------------------\n");
        writeDebugStream("their eru svipadir motor er hradari \n",);
        writeDebugStream("left - encoder %d \n", abs(SensorValue[leftEncoder]));
   			writeDebugStream("right - encoder %d \n", abs(SensorValue[rightEncoder]));
   			writeDebugStream("--------------------------------------------------\n");
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
	ResetMotor();
}

void MoveBackward(float cm)
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
