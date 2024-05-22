#include <stdio.h>

int matrice[6][6] = {{1,0,0,0,0,0}, {0,1,0,1,1,1}, {0,0,1,0,1,0}, {1,1,0,0,1,0}, {1,0,1,1,0,0}, {1,0,0,0,0,1}};

int i, j, k, l;

int flag0 = 0;

void print(int arg_matrice[6][6]){
	for(i = 0; i<6; i++){
		for(j = 0; j<6; j++){
			printf("%d ", arg_matrice[i][j]);
		}
		printf("\n");
	}
}

(int*)[6] func(int arg_matrice[6][6]){ 
	for(i = 0; i<6; i++){
		for(j = 0; j<6; j++){
			if((i!=0) && (j!=0) && (i!=5) && (j!=5)){
				//our neighbourhoods are [i-1][j-1] to [i+1][j+1] excluding [i][j] itself
				flag0 = 0;
				for(k=i-1; k<=i+1; k++){
					for(l=j-1; l<=j+1; l++){
						if(!((k==i) && (l==j))){
							if((arg_matrice[k][l]==1) && ((k == 0)||(l == 0)|| (k == 5)||(l == 5))){
								
								k = i+1; l= j+1;
								flag0 = 1;
								
							}
						}
					}
				}
				if((flag0!=1) && (arg_matrice[i][j]==1)){
					arg_matrice[i][j] = 0;
					flag0 = 0;
				}
			}
		}
		
	}
	return arg_matrice;
	
}

int main() {
	print(matrice);
	printf("\n");
	func(matrice);
	print(matrice);
	return 0;
}
