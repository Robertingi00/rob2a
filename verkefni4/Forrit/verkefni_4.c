/*----------------------------------------------------------------------------------------------------*\
|*                           - Dual Joystick Control with Arm - 1 Remote -                            *|
|*                                      ROBOTC on VEX 2.0 Cortex                                      *|
|*                                                                                                    *|
|*  Í verkefni 4 áttum að láta vélmennið að keyra endlaust áfram og aldrei klessa á neitt.            *|
|*  Við erum með sensora fyrir framan á robotinum sem skynjar hvort vélemennið sé að fara klessa á.   *|
\*----------------------------------------------------------------------------------------------------*/

//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
bool task_start = false;

task DriveStraight_verk4()
{
	while(true){
	    if (abs(SensorValue[rightEncoder]) + 20 < abs(SensorValue[leftEncoder])){
	        motor[rightMotor] = FullPower+10;
	        motor[leftMotor] = (FullPower-10);

	    }else if(abs(SensorValue[leftEncoder]) + 20 < abs(SensorValue[rightEncoder])){
	        motor[rightMotor] =(FullPower-10);
	        motor[leftMotor] = (FullPower+10);


	    }else{
	        motor[rightMotor] = FullPower;
	        motor[leftMotor] = FullPower;


	    }
	    writeDebugStream("----------------------------------------------------\n");
	    writeDebugStream("rightMotor = %d Encoder = %d\n",motor[rightMotor],abs(SensorValue[rightEncoder]));
	    writeDebugStream("leftMotor = %d Encoder = %d\n",motor[leftMotor],abs(SensorValue[leftEncoder]));
			writeDebugStream("----------------------------------------------------\n");
	}
}

int printRandoms(int lower, int upper)
{
	int i;
	for (i = 0; i < 1; i++) {
		int num = (rand() %
		(upper - lower + 1)) + lower;
		return num;
	}
}






void MoveForward_verk4(bool att)
{
	if (task_start == false){
		StartTask(DriveStraight_verk4);
		task_start = true;
	}
}

void verkefni_4()
{
	while(true)
	{
		if(SensorValue[sonar] > 40)
		{
			MoveForward_verk4(true);
		}else{
			StopTask(DriveStraight_verk4);
			task_start = false;
			ResetMotor();
			int random_number =  printRandoms(0, 1);
			if (random_number == 1){
				TurnRight(90);
			}else{
				TurnLeft(90);
			}


		}
		while(SensorValue[lightSensor] > 200) // While the ambient lightSensor reads a value less than 200
		{
			StopTask(DriveStraight_verk4);
			task_start = false;
			ResetMotor();
		}
		clearLCDLine(0);
		clearLCDLine(1);
		displayLCDPos(0,0);
		displayNextLCDString("Stopa verkefni");
		displayLCDPos(1,6);
		displayNextLCDString("Yes");
		wait1Msec(250);
		if(nLCDButtons == 2){
			ResetMotor();
			StopTask(DriveStraight_verk4);
			break;
		}
	}
}
