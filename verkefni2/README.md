# Verkefni 2

## Hluti 1

Hlut1 1 snérist um að nota tíma til að láta robitinn fara aframm um 50 cm og afturm um 50 cm 5 sinnum, og hækka vegalengina með 50 í hvert skipti.
Þessi liður var frekar léttur að leysa en var góður inngangur fyrir áfanngan.

#### Flowchart

Inline-style: 
![alt text](https://github.com/adam-p/markdown-here/raw/master/src/common/images/icon48.png "Logo Title Text 1")


#### Myndband

<a href="https://www.youtube.com/watch?v=lG1IULf8ywg&feature=youtu.be" target="_blank"><img src="http://img.youtube.com/vi/YOUTUBE_VIDEO_ID_HERE/0.jpg" 
alt="IMAGE ALT TEXT HERE" width="240" height="180" border="10" /></a>

## Hluti 2

Hlut1 2 var svipaður og fyrsti hlutinn, en í honum átti maður að nota vegalengd. Þetta leit út fyrir að vera létta og allt var að virka nema að hann var að keyra skakkt. Okkur leist ekki á það og reyndum að finna leið til að laga það, við ákvöðum að hafa void sem lætur robotinn keyra beint.
```c
void DriveStraight(bool att)
{
    if (abs(SensorValue[rightEncoder]) + 20 < abs(SensorValue[leftEncoder])){
        if (att){
            motor[rightMotor] = FullPower+10;
            motor[leftMotor] = (FullPower-10);
        }else{
            motor[rightMotor] = -(FullPower+20);
            motor[leftMotor] = -(FullPower-20);

        }

    }else if(abs(SensorValue[leftEncoder]) + 20 < abs(SensorValue[rightEncoder])){
      if (att){
            motor[rightMotor] =(FullPower-10);
            motor[leftMotor] = (FullPower+10);
        }else{

            motor[rightMotor] = -(FullPower-20);
            motor[leftMotor] = -(FullPower+20);
        }

    }else{
        if (att){
            motor[rightMotor] = FullPower;
            motor[leftMotor] = FullPower;
        }else{
            motor[rightMotor] = -(FullPower);
            motor[leftMotor] = -(FullPower);
        }

    }

}
```

#### Flowchart

Inline-style: 
![alt text](https://github.com/adam-p/markdown-here/raw/master/src/common/images/icon48.png "Logo Title Text 1")


#### Myndband

<a href="https://www.youtube.com/watch?v=J3qLPHMmgDE&feature=youtu.be" target="_blank"><img src="http://img.youtube.com/vi/YOUTUBE_VIDEO_ID_HERE/0.jpg" 
alt="IMAGE ALT TEXT HERE" width="240" height="180" border="10" /></a>

## Hluti 1

Hlut1 3 þurftum við að búa til nýtt fall sem lætur hann beyja. Það er búið að vera það erfiðasta í áfnganum. Þetta void mund tengast næstum öllum verkefnunum á eftir þessum og var það ekki alltaf að virka. Við töldum okkur sigraða og settum Gyroscope á hann og það virkaði bara vel.

#### Flowchart

Inline-style: 
![alt text](https://github.com/adam-p/markdown-here/raw/master/src/common/images/icon48.png "Logo Title Text 1")


#### Myndband

<a href="https://www.youtube.com/watch?v=rGqQjMJ9WO8&feature=youtu.be" target="_blank"><img src="http://img.youtube.com/vi/YOUTUBE_VIDEO_ID_HERE/0.jpg" 
alt="IMAGE ALT TEXT HERE" width="240" height="180" border="10" /></a>

