
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "../../program_connector/Functions.c"
bool task_start = false;
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*----------------------------------------------------------------------------------------------------*\
|*                           - Dual Joystick Control with Arm - 1 Remote -                            *|
|*                                      ROBOTC on VEX 2.0 Cortex                                      *|
|*                                                                                                    *|
|*  This program uses both the Left and the Right joysticks to run the robot using "tank control".    *|
|*  The Group 6 buttons on the top-right of the VEXnet Joystick are used to raise and lower an arm.   *|
|*                                                                                                    *|
|*                                        ROBOT CONFIGURATION                                         *|
|*    NOTES:                                                                                          *|
|*    1)  Ch1 is the X axis and Ch2 is the Y axis for the RIGHT joystick.                             *|
|*    2)  Ch3 is the Y axis and Ch4 is the X axis for the LEFT joystick.                              *|
|*                                                                                                    *|
|*    MOTORS & SENSORS:                                                                               *|
|*    [I/O Port]              [Name]              [Type]              [Description]                   *|
|*    Motor - Port 2          rightMotor           VEX Motor           Right motor                    *|
|*    Motor - Port 3          leftMotor            VEX Motor           Left motor                     *|
|*    Motor - Port 6          armMotor             VEX Motor           Arm motor                      *|
\*----------------------------------------------------------------------------------------------------*/

//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++

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
	StartTask(stop);

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
				TurnRight90();
			}else{
				TurnLeft90();
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