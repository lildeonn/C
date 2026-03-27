#include <stdio.h>
#include "lab4.h"

int main(){
	double a[3];
	int i;
	
	for(i=0; i<3; i++){
        printf("vvedite dlini storon : ");
        scanf("%lf", &a[i]);
	}
	for(i=0; i<3; i++){
		printf("dlini : %lf ", a[i]);
	}
	
	return 0;
}
