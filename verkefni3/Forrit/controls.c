#pragma config(UART_Usage, UART1, uartVEXLCD, baudRate19200, IOPins, None, None)
#pragma config(UART_Usage, UART2, uartNotUsed, baudRate4800, IOPins, None, None)
#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in5,    ArmeEncoder,    sensorPotentiometer)
#pragma config(Sensor, dgtl1,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl12, touchSensor,    sensorTouch)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_2,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Motor,  port1,           rightMotor,    tmotorVex393HighSpeed, openLoop, encoder, encoderPort, I2C_2, 1692728)
#pragma config(Motor,  port4,           armMotor,      tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port5,           handMotor,     tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port10,          leftMotor,     tmotorVex393HighSpeed, openLoop, reversed, encoder, encoderPort, I2C_1, 1692728)

/*----------------------------------------------------------------------------------------------------*\
|*                           - Dual Joystick Control with Arm - 1 Remote -                            *|
|*                                      ROBOTC on VEX 2.0 Cortex                                      *|
|*                                                                                                    *|
|*  Í verkefni 3 eigum við að láta fjarstýringu stýra vélmennið. Það getur keyrt áfram og til baka,   *|
|*  snúið sig í hringi og lift um arminn og opnað höndina.                                            *|
\*----------------------------------------------------------------------------------------------------*/

//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++

task controls()
{
	SensorValue[ArmeEncoder] = 0;
  while(1 == 1)
  {
    //Driving Motor Control
    //motor[leftMotor] = vexRT[Ch3];
    //motor[rightMotor] = vexRT[Ch2];

    //Arm Control
    if(vexRT[Btn6U] == 1)
    {
      if(SensorValue[ArmeEncoder] > 300 && SensorValue[ArmeEncoder] < 1500){
     	 	motor[armMotor] = 40;
    	}else{
    		motor[armMotor] = 0;
    	}
    }
    else if(vexRT[Btn6D] == 1)
    {
      if(SensorValue[ArmeEncoder] < 1140){
     		motor[armMotor] = -10;
    	}
    	else{
    		motor[armMotor] = 0;
    	}
    }
    else
    {
      motor[armMotor] = 0;
    }


    if(vexRT[Btn5U] == 1)
    {
     	 motor[handMotor] = 40;
		}
    else if(vexRT[Btn5D] == 1)
  	{
     	 motor[handMotor] = -40;
  	}
    else
    {
      motor[handMotor] = 0;
    }
  }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
