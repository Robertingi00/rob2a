# Verkfni 4

Verkefni 4 var ekki það erfitt. En eina sem stoppaði okkur var að beyja 90°. Robotinn beygði alltaf milli 80 - 120°. Náðum ekki að laga það, en þegar við notum Gyroscope vikraði það mun betur.
Svo notuðum við drive_straight fallið með smá breytingu, við breyttum því í task og létum að virka þannig að það keyrir þangað til að við seigjum annað.

```c
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

```

#### Flowchart


![alt text](./Forrit/flowchart.png "Logo Title Text 1")


#### Myndband

<a href="https://www.youtube.com/edit?o=U&video_id=IAEh6lwXlPg" target="_blank"><img src="http://img.youtube.com/vi/IAEh6lwXlPg/0.jpg" 
alt="IMAGE ALT TEXT HERE" width="100%" border="10" /></a>
