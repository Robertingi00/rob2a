# Verkefni 2

## Hluti 1

Hlut1 snérist um að nota tíma til að láta robitinn fara aframm um 50 cm og afturm um 50 cm 5 sinnum, og hækka vegalengina með 50 í hvert skipti.
Þessi liður var frekar léttur að leysa en var góður inngangur fyrir áfanngan.

#### Flowchart

![alt text](./Forrit/Hlutar/hluti1/flowchart_verk2_hluti1.PNG "Logo Title Text 1")
#### Myndband

<a href="https://www.youtube.com/watch?v=lG1IULf8ywg&feature=youtu.be" target="_blank"><img src="http://img.youtube.com/vi/lG1IULf8ywg/0.jpg" 
alt="IMAGE ALT TEXT HERE" width="100%" border="10" /></a>

## Hluti 2

Hluti2 var svipaður og fyrsti hlutinn, en í honum átti maður að nota vegalengd. Þetta leit út fyrir að vera létta og allt var að virka nema að hann var að keyra skakkt. Okkur leist ekki á það og reyndum að finna leið til að laga það, við ákvöðum að hafa void sem lætur robotinn keyra beint.
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

<img src="\images\emoticons\cool.png">
![alt text](https://github.com/Robertingi00/rob2a/blob/master/verkefni2/Forrit/Hlutar/hluti2/flowchart_verk2_hluti2.PNG "Logo Title Text 1")


#### Myndband

<a href="https://www.youtube.com/watch?v=J3qLPHMmgDE&feature=youtu.be" target="_blank"><img src="http://img.youtube.com/vi/J3qLPHMmgDE/0.jpg" 
alt="IMAGE ALT TEXT HERE" width="240" height="180" border="10" /></a>

## Hluti 2

Hlut1 3 þurftum við að búa til nýtt fall sem lætur hann beyja. Það er búið að vera það erfiðasta í áfnganum. Þetta void mund tengast næstum öllum verkefnunum á eftir þessum og var það ekki alltaf að virka. Við töldum okkur sigraða og settum Gyroscope á hann og það virkaði bara vel.

#### Flowchart

<img src="https://github.com/Robertingi00/rob2a/blob/master/verkefni2/Forrit/Hlutar/hluti3/flowchart_verk2_hluti3.PNG">



#### Myndband

<a href="https://www.youtube.com/watch?v=rGqQjMJ9WO8&feature=youtu.be" target="_blank"><img src="http://img.youtube.com/vi/rGqQjMJ9WO8/0.jpg" 
alt="IMAGE ALT TEXT HERE" width="240" height="180" border="10" /></a>

