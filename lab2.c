#include <stdio.h>
#include <math.h>

int main(){
    double a[3][3];
    double so = 0, sp = 0;
    int i, j;
    int max = 3;

    for(i=0; i <3; i++){
      for(j=0; j <3; j++){
        printf("znachenia a[%d][%d] = \n", i, j);
        scanf("%lf", &a[i][j]);
      }
    }

    for(i=0; i < max; i++){
      for(j=0; j < max; j++){
        if(i == j){
          so += a[i][j];
        }
        if(i + j == max - 1){
          sp += a[i][j];
        }
      }
    }

    printf("osnovnaya^ %lf\npobochnaya^ %lf\n", so, sp);
    
    /*______________________________________________*/
    
	int b[2][2];
	int s = 0;
	
	for(i=0; i < 2; i++){
      for(j=0; j < 2; j++){
        printf("znachenia b[%d][%d] = \n", i, j);
        scanf("%d", &b[i][j]);
        s += b[i][j];
      }
    }
    int kvad = pow(s, 2);
	printf("kvadrat b: %d", kvad);
    
	return 0;
}
