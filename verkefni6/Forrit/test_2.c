//1,0
//0,1
//-1,1


//Ef boltinn er ekki i x=1 fra boltan i einn og baeta eda taka fra x.

//2,-3


//Feru  byjuna ef Tharf
//Beygju rett
//Fardu aframm ein of og thad thraf
//beygdu rett
// fardu aframm


int robot[2] = {0,3};
int obj[2] = {2,0};




void Move_to(int *robot,int *obj)
{
	int att;
	int ferdX = obj[0] - robot[0];
	int ferdY = obj[1] - robot[1];
	if(ferdY % 1  == 0){
		att = 1;
	}else{
		att = -1;
	}

	if(robot[0] != 1){
		switch(ferdX){
			case -2:
				robot[0] ++;
				ferdX ++;
				writeDebugStream("Robotinn fer i midjuna fra 0");
				if(att == 1){
						writeDebugStream("Robotinn beyjir til haegri \n");
				}else{
						writeDebugStream("Robotinn beyjir til vinstri \n");
				}
				break;
			case 2:
				robot[0] --;
				ferdX --;
				writeDebugStream("Robotinn fer i midjuna fra 2\n");

				if(att == 1){
						writeDebugStream("Robotinn beyjir til vinstir \n");
				}else{
						writeDebugStream("Robotinn beyjir til Haegri \n");
				}
				break;
			case 0:
				if(robot[0] == 2){
						robot[0] --;
						ferdX ++;
						writeDebugStream("Robotinn fer i midjuna fra 2\n");
						writeDebugStream("att %d", att )
						if(att == 1){
								writeDebugStream("Robotinn beyjir til vinstir \n");
						}else{
								writeDebugStream("Robotinn beyjir til Haegri \n");
						}
				}else{
					robot[0] ++;
					ferdX --;
					writeDebugStream("Robotinn fer i midjuna fra 0\n");

					if(att == 1){
							writeDebugStream("Robotinn beyjir til hagri \n");
					}else{
							writeDebugStream("Robotinn beyjir til vinstri \n");
					}
				}
				break;
			}
		}
		for(int i = 0; i < abs(ferdY);i ++){

			if(att == 1){
				writeDebugStream("Robotinn fer nidur \n");
				robot[1] ++;
			}else{
				writeDebugStream("Robotinn fer upp \n");
				robot[1] --;
			}
		}


		if(ferdX == -1){
			switch(att){
				case -1:
					writeDebugStream("Robotinn beyjir til hagri \n");
					break;

				case 1:
					writeDebugStream("Robotinn beyjir til vinstri \n");
					break;
			}
		}else if(ferdX == 1){
			switch(att){
				case -1:
					writeDebugStream("Robotinn beyjir til vinstri \n");
					break;

				case 1:
					writeDebugStream("Robotinn beyjir til hagri \n");
					break;
			}

		}
		writeDebugStream("Robotinn fer aframm \n");

		robot[0] = robot[0] + ferdX;

		writeDebugStream("robotinn er kominn x = %d y = %d \n",robot[0],robot[1]);



}


task main()
{
	Move_to(robot,obj);

}
