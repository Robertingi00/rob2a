int robot[2] = {1,0};
int glas_1[2] = {2,0};
int glas_2[2] = {0,1};
int glas_3[2] = {2,2};
int glas_4[2] = {2,4};
int glos[4][2] = {{2,0},{0,1},{2,2},{2,4}};
int karfa[2] = {0,3};

void find_object(int *robot, int *obj)
{
	int ferdX = obj[0] - robot[0];
	int ferdY = obj[1] - robot[1];
	int att; // 1 er ad fara nidur -1 er ad fara upp.
	// writeDebugStream("%d",ferdX);
	writeDebugStream("Robot Byrjar x = %d y = %d \n", robot[0],robot[1]);
	writeDebugStream("Obj Byrjar x = %d y = %d \n", obj[0],obj[1]);

	if(ferdY >= 0){
		att = 1;
	}else{
		att = -1;
	}

	if(ferdX != 1 || ferdX != -1){ // Ef robotinn er midju linunni sleppur hann thessum linum.
		if(ferdX == 2 || ferdX == -2){
			if(ferdX == 2){
				ferdX --;
				robot[0] ++;
				writeDebugStream("Robot fer i midjuna lina 17 \n");
				switch(att){
					case 1:
						writeDebugStream("robot fer til haegri \n");
						break;
					case -1:
						writeDebugStream("Robot fer til vinstri \n");
						break;
				}

			}else if(ferdX == -2){
				ferdX ++;
				robot[0] --;
				writeDebugStream("Robot fer i midjuna lina 21 \n");
				switch(att){
					case 1:
						writeDebugStream("robot fer til vinstir \n");
						break;
					case -1:
						writeDebugStream("robot fer til haegri \n");
						break;
				}

			}else{
				writeDebugStream("Villa  forritinu lina 22 \n");
			}

		}else if(ferdX == 0){
			if(robot[0] < 1){
				ferdX --;
				robot[0] ++;
				writeDebugStream("Robot fer i midjuna lina 30 \n");
				switch(att){
					case 1:
						writeDebugStream("robot fer til haegri \n");
						break;
					case -1:
						writeDebugStream("robot fer til vinstir \n");
						break;
				}

			}else if(robot[0] > 1){
				ferdX ++;
				robot[0] --;
				writeDebugStream("Robot fer i midjuna lina 34 \n");
				switch(att){
					case 1:
						writeDebugStream("robot fer til vinstri \n");
						break;
					case -1:
						writeDebugStream("robot fer til haegri \n");
						break;
				}

			}
			else{
				writeDebugStream("Villa  forritinu lina 36 \n");
			}
		}
	}



	writeDebugStream("Robot endar x = %d y = %d \n", robot[0],robot[1]);

	writeDebugStream("--------\n");
	for(int i = 0;i < abs(ferdY);i ++){
		switch(att){
				case 1:
					robot[1] ++;
					writeDebugStream("robot fer nidur\n");
					break;
				case -1:
					robot[1] --;
					writeDebugStream("robot fer upp\n");
					break;

		}

	}


	writeDebugStream("--------\n");


		switch(att){
				case 1:
					if(ferdX < 0){
						robot[0] --;
						writeDebugStream("Robot fer til haegri og svo afram line 113 \n");
					}else if(ferdX > 0){
						robot[0] ++;
						writeDebugStream("Robot fer til vinstir og svo afram  lina 116 \n");
					}else{
						writeDebugStream("Villa i linu 79 \n");
					}
					break;
				case -1:
					if(ferdX < 0){
						robot[0] --;
						writeDebugStream("Robot fer til vinstir og svo afram line 124 \n");
					}else if(ferdX > 0){
						robot[0] ++;
						writeDebugStream("Robot fer til haegri og svo afram line 127 \n");
					}else{
						writeDebugStream("Villa i linu 79 \n");
					}
					break;

		}

	writeDebugStream("Robot endar x = %d y = %d \n", robot[0],robot[1]);
}



task main
{
	find_object(robot, glas_1);
	writeDebugStream("############### karfa \n");
	find_object(robot, karfa);
	writeDebugStream("############### glas_2 \n");
	find_object(robot, glas_2);
	writeDebugStream("############### karfa\n");
	find_object(robot, karfa);
	writeDebugStream("############### \n");
	find_object(robot, glas_3);
	writeDebugStream("############### \n");
	find_object(robot, karfa);
	writeDebugStream("############### \n");
	find_object(robot, glas_4);
	writeDebugStream("############### \n");
	find_object(robot, karfa);
}
