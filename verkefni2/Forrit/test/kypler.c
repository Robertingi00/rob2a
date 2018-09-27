void ResetEncodersNew()
{
   // SensorValue[rightEncoder] = 0;
  // 	SensorValue[leftEncoder] = 0;
}

float test(float cm){
  float tala = (cm / 33.0) * 360.0;
  return tala;
}

void MoveForwardNew(float cm)
{
	ResetEncodersNew();
	float degree = test(cm);
	writeDebugStream("deggree %d \n", degree);

	while(abs(SensorValue[rightEncoder]) < degree){
	//	motor[rightMotor] = 80;
	//	motor[leftMotor] = 80;
	}
}

void MoveBackwardNew(int cm)
{
	ResetEncodersNew();
	float degree = test(cm);
	while(abs(SensorValue[rightEncoder]) < degree){
		//motor[rightMotor] = -80;
		//motor[leftMotor] = -80;
	}
}
