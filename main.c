#include <stdio.h>

int matrix[6][6] = {{1,0,0,0,0,0}, {0,1,0,1,1,1}, {0,0,1,0,1,0}, {1,1,0,0,1,0}, {1,0,1,1,0,0}, {1,0,0,0,0,1}};

int loop0, loop1, loop2, loop3;

int flag0 = 0;

void print(int arg_matrix[6][6]){
	for(loop0 = 0; loop0<6; loop0++){
		for(loop1 = 0; loop1<6; loop1++){
			printf("%d ", arg_matrix[loop0][loop1]);
		}
		printf("\n");
	}
}

int func(int arg_matrix[6][6]){ 
	for(loop0 = 0; loop0<6; loop0++){
		for(loop1 = 0; loop1<6; loop1++){
			if((loop0!=0) && (loop1!=0) && (loop0!=5) && (loop1!=5)){
				//our neighbourhoods are [i-1][j-1] to [i+1][j+1] excluding [i][j] itself
				flag0 = 0;
				for(loop2=loop0-1; loop2<=loop0+1; loop2++){
					for(loop3=loop1-1; loop3<=loop1+1; loop3++){
						if(!((loop2==loop0) && (loop3==loop1))){
							if((arg_matrix[loop2][loop3]==1) && ((loop2 == 0)||(loop3 == 0)|| (loop2 == 5)||(loop3 == 5))){
								
								loop2 = loop0+1; loop3= loop1+1;
								flag0 = 1;
								
							}
						}
					}
				}
				if((flag0!=1) && (arg_matrix[loop0][loop1]==1)){
					arg_matrix[loop0][loop1] = 0;
					flag0 = 0;
				}
			}
		}
		
	}
}

int main() {
	print(matrix);
	printf("\n");
	func(matrix);
	print(matrix);
	return 0;
}
