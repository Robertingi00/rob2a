/*----------------------------------------------------------------------------------------------------*\
|*                                            - Bip  -                                                *|
|*                                      ROBOTC on VEX 2.0 CORTEX                                      *|
|*                                                                                                    *|
|*  Hlutarnir eru lýstir í 'hlutar' skjalinu    						      *|
|*                                               						      *|
\*-----------------------------------------------------------------------------------------------4246-*/
int const timi = 1.388888889;

void hluti_1()
{
	for (int i = 1; i <= 5;i++){
		motor[rightMotor] = 127;
		motor[leftMotor]  = 127;
		wait1Msec((timi*i)*1000);

		motor[rightMotor] = 0;
		motor[leftMotor]  = 0;
		wait1Msec(1000);

		motor[rightMotor] = -127;
		motor[leftMotor]  = -127;
		wait1Msec((timi*i)*1000);

		motor[rightMotor] = 0;
		motor[leftMotor]  = 0;
		wait1Msec(1000);
	}
	return;
}

void hluti_2()
{
	for (int i = 1;i <= 5; i++){
			MoveForward_cm(50*i);
			wait1Msec(2000);
			MoveBackward_cm(50*i);
			wait1Msec(2000);
	}
}

void hluti_3(){

	wait1Msec(1000);
	MoveForward_cm(50);
	TurnLeft(90);

	wait1Msec(1000);
	MoveForward_cm(50);
	TurnRight(90);

	wait1Msec(1000);
	MoveForward_cm(50);
	TurnRight(90);

	wait1Msec(1000);
	MoveForward_cm(50);
}
