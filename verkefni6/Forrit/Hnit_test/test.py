const array hnit_upphaf = [[0,0,0],[0,0,0],[0,0,0],[0,0,0],[0,0,0]]

array get_hnit(int x, int y){
	temp_hnit = hnit_upphaf;
	temp_hnit[y][x] = 1;

	return temp_hnit
}

array bolti1 = get_hnit(2, 0);
array bolti2 = get_hnit(0, 1);
array bolti3 = get_hnit(2, 2);
array bolti4 = get_hnit(2, 4);

array robot = get_hnit(1, 0);

array karfa = get_hnit(0, 3);