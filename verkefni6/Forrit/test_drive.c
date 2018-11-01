const int dist = 50;//cm
int robot[2] = {0,1};
int object[2] = {4,2};

void Move_to_object(obj){
	if(robot[0] == obj[0]){
			if(robot[1] > obj[1]){
				robot[1] --;
				//kalla  keyra function
		}else{
			robot[1] ++;
			//kalla  keyra function
		}
	}else{
		if(robot[0] !=){

		}
	}

}

task main()
{
	while(true){
		writeDebugStream("%d\n",object[1]);

	}
}
