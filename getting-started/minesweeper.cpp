#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define M 10000
#define N 10000

char mine[M][N];
int size_m;
int size_n;
int test = 1;

int count_adjacent_mine(int pos_m,int pos_n){
	int count = 0;

	if (pos_m+1 < size_m && mine[pos_m+1][pos_n] == '*'){//0X0
		count++;
	}
	if (pos_m-1 >=0 && mine[pos_m-1][pos_n] == '*'){//0X0
		count++;
	}
	if (pos_m+1 < size_m && pos_n+1 < size_n &&  mine[pos_m+1][pos_n+1] == '*'){ //00X
		count++;
	}
	if (pos_m+1 < size_m && pos_n-1 >=0 &&  mine[pos_m+1][pos_n-1] == '*'){ //00X
		count++;
	}
	if (pos_m-1 >=0  && pos_n+1 < size_n &&  mine[pos_m-1][pos_n+1] == '*'){ //00X
		count++;
	}
	if (pos_m-1 >=0  && pos_n-1 >= 0 && mine[pos_m-1][pos_n-1] == '*'){//X00
		count++;
	}
	if (pos_n+1 < size_n && mine[pos_m][pos_n+1] == '*'){//00X
		count++;
	}
	if (pos_n-1 >=0 && mine[pos_m][pos_n-1] == '*'){//X00
		count++; 
	}
	return count;
}

void print_all_count_adjacent_mine(){
   if (test > 1) 	printf ("\n");
   
	printf ("Field #%d:\n",test++);
	for (int i = 0; i < size_m; i++){
		for (int j = 0; j < size_n; j++){
			if (mine[i][j] == '*'){
				printf ("*");
			}else{
				int total = count_adjacent_mine(i,j);
				printf ("%d",total);
			}	
		}
		printf ("\n");
	}
}

int main(){

	while (1){
		scanf ("%d%d",&size_m,&size_n);
		if (size_m == 0 && size_n == 0) break;
		for (int i = 0; i < size_m; i++){
			for (int j = 0; j < size_n; j++){
				scanf (" %c",&mine[i][j]);
			} 
		}	   
		print_all_count_adjacent_mine();
	}
	return 0;
}







