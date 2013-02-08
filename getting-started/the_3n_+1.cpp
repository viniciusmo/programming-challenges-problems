#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int count_cycle_lenght( int );
int max_cycle_lenght_between(int,int);

int main(){
	int n1;
	int n2;
	while ( (scanf ("%d%d",&n1,&n2))  != EOF){
		int max_cycle = max_cycle_lenght_between(n1,n2);
		printf ("%d %d %d\n",n1,n2,max_cycle);
	}
	return 0;
}

int max_cycle_lenght_between(int n1,int n2){
	int a = min (n1,n2);
	int b = max (n1,n2);
	int max_cycle = 0;

	for ( int i = a; i <= b; i++){
		int result = count_cycle_lenght(i);
		max_cycle = max(result,max_cycle);
	}
	return max_cycle;
}

int  count_cycle_lenght( int n1){
	int count_cycle = 0;
	while (n1 != 1 ){ 
		if ( (n1 % 2)  == 0){
			n1 /= 2;
		}else{
			n1 *=3;
			n1++;
		}
		count_cycle++;
	}
	count_cycle++;	
	return count_cycle;
}




















