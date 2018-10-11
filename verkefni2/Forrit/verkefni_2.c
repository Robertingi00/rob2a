/*----------------------------------------------------------------------------------------------------*\
|*                                            - Bip  -                                                *|
|*                                      ROBOTC on VEX 2.0 CORTEX                                      *|
|*                                                                                                    *|
|*  This program instructs your robot to move forward at full power for three seconds.  There is a    *|
|*  two second pause at the beginning of the program.                                                 *|
|*                                                                                                    *|
|*                                        ROBOT CONFIGURATION                                         *|
|*    NOTES:                                                                                          *|
|*    1)  Reversing 'rightMotor' (port 2) in the "Motors and Sensors Setup" is needed with the        *|
|*        "Squarebot" mode, but may not be needed for all robot configurations.                       *|
|*    2)  Power levels that can be assigned to a motor port range from -127 (full reverse) to         *|
|*        127 (full forward).                                                                         *|
|*                                                                                                    *|
|*    MOTORS & SENSORS:                                                                               *|
|*    [I/O Port]          [Name]              [Type]                [Description]                     *|
|*    Motor Port 2        rightMotor          VEX 3-wire module     Right side motor                  *|
|*    Motor Port 3        leftMotor           VEX 3-wire module     Left side motor                   *|
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
	}
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
	MoveForward_cm(50);
	wait1Msec(1000);
	TurnLeft90();

	wait1Msec(1000);
	MoveForward_cm(50);
	wait1Msec(1000);
	TurnRight90();

	wait1Msec(1000);
	MoveForward_cm(50);
	wait1Msec(1000);
	TurnRight90();

	wait1Msec(1000);
	MoveForward_cm(50);
	wait1Msec(1000);

	MoveForward_cm(50);
	wait1Msec(1000);
	TurnLeft90();
}
