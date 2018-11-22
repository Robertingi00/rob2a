#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in4,    lightSensor,    sensorReflection)
#pragma config(Sensor, in5,    ArmeEncoder,    sensorPotentiometer)
#pragma config(Sensor, dgtl1,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl8,  sonar,          sensorSONAR_cm)
#pragma config(Sensor, dgtl12, touchSensor,    sensorTouch)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_2,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Motor,  port1,           rightMotor,    tmotorVex393HighSpeed, openLoop, encoder, encoderPort, I2C_2, 1692728)
#pragma config(Motor,  port10,          leftMotor,     tmotorVex393HighSpeed, openLoop, reversed, encoder, encoderPort, I2C_1, 1692728)
#pragma config(Motor,  port4,           armMotor,      tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port5,           handMotor,     tmotorServoContinuousRotation, openLoop)
#pragma config(Sensor, in7,    lineFollowerRIGHT,   sensorLineFollower)
#pragma config(Sensor, in2,    lineFollowerCENTER,  sensorLineFollower)
#pragma config(Sensor, in8,    lineFollowerLEFT,    sensorLineFollower)

const int threshold = 1000;




void turnLeft()
{
	SensorType[in3] = sensorNone;
	wait1Msec(1000);
	SensorType[in3] = sensorGyro;
	wait1Msec(2000);

	while(true)
	  {
	    motor[rightMotor] = 63;
	    motor[leftMotor] = -63;

	    if(SensorValue(lineFollowerCENTER) > 1000){break;}
	}
	motor[rightMotor] = -15;
	motor[leftMotor] = 15;
	Wait1Msec(250);

}

void move()
{
	if(SensorValue(lineFollowerRIGHT) > threshold)
    {
      // counter-steer right:
      motor[leftMotor]  = 100;
      motor[rightMotor] = 0;
    }
    // CENTER sensor sees dark:
    if(SensorValue(lineFollowerCENTER) > threshold)
    {
      // go straight
      motor[leftMotor]  = 63;
      motor[rightMotor] = 63;
    }
    // LEFT sensor sees dark:
    if(SensorValue(lineFollowerLEFT) > threshold)
    {
      // counter-steer left:
      motor[leftMotor]  = 0;
      motor[rightMotor] = 100;
    }

}


task main(){
	turnLeft();
	while(true){
		move();
	}
}
