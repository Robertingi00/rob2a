/*----------------------------------------------------------------------------------------------------*\
|*                           - Dual Joystick Control with Arm - 1 Remote -                            *|
|*                                      ROBOTC on VEX 2.0 Cortex                                      *|
|*                                                                                                    *|
|*  Vélmennið eltir svarta línu.                                                                      *|
\*----------------------------------------------------------------------------------------------------*/

//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++


void verkefni_5()
{
	bool afram;
	afram = true;
  int threshold = 400;      /* found by taking a reading on both DARK and LIGHT    */
                            /* surfaces, adding them together, then dividing by 2. */

  do{
  	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -+
    displayLCDCenteredString(0, "LEFT  CNTR  RGHT");        //  Display   |
    displayLCDPos(1,0);                                     //  Sensor    |
    displayNextLCDNumber(SensorValue(lineFollowerLEFT));    //  Readings  |
    displayLCDPos(1,6);                                     //  to LCD.   |
    displayNextLCDNumber(SensorValue(lineFollowerCENTER));  //            |
    displayLCDPos(1,12);                                    //  L  C  R   |
    displayNextLCDNumber(SensorValue(lineFollowerRIGHT));   //  x  x  x   |
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -+

    // RIGHT sensor sees dark:
    if(SensorValue(lineFollowerRIGHT) > threshold)
    {
      // counter-steer right:
      motor[leftMotor]  = 120;
      motor[rightMotor] = -10;
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
      motor[leftMotor]  = -10;
      motor[rightMotor] = 100;
    }
    if(SensorValue(lineFollowerLEFT) < threshold && SensorValue(lineFollowerRIGHT) < threshold && SensorValue(lineFollowerCENTER) < threshold)
    {
    		motor[leftMotor]  = 0;
     	  motor[rightMotor] = 0;
     	  afram = false;
    }
  }
  while(afram);

  return;
}
