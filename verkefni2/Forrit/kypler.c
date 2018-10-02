void ResetEncodersNew()
{
    SensorValue[rightEncoder] = 0;
  	SensorValue[leftEncoder] = 0;
}

float test(int cm){
  float tala = ((float)cm / (float)33) * 360;
  return tala;
}

void MoveForwardNew(int cm)
{
	ResetEncodersNew();
	float degree = test(cm);
	while(abs(SensorValue[rightEncoder]) < degree){
		motor[rightMotor] = 80;
		motor[leftMotor] = 80;
	}
}

void MoveBackwardNew(int cm)
{
	ResetEncodersNew();
	float degree = test(cm);
	while(abs(SensorValue[rightEncoder]) < degree){
		motor[rightMotor] = -80;
		motor[leftMotor] = -80;
	}
}
