#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>

using namespace std;

#define MAX_STUDENT 1000

double student_spent[MAX_STUDENT];
double total_high = 0.0;
double total_low = 0.0;

double sum (int n){
	double result = 0;
	for (int i = 0; i < n; i++){
		result += student_spent[i];
	} 
	return result;
}

int main (){
	int  n;
	while (scanf ("%d",&n) != EOF  && n!=0){
		for (int i = 0; i < n; i++){
			scanf ("%lf",&student_spent[i]);
		}
		double avg = sum(n)/n;
		for (int i = 0; i < n; i++){
			double result = student_spent[i] - avg;
			if (result >= 0) total_high+= floor(result*100)/100;
			else total_low -= ceil(result*100)/100;
		}
		printf("$%.2f\n",max(total_low,total_high));
		total_high = 0;
		total_low = 0;
	}
	return 0;
}	




