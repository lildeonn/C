#include <stdio.h>
#include <math.h>
int main() {
  while( 1 == 1){
    double a, b, c, x1, x2, d;  
    scanf("%lf", &a);
    scanf("%lf", &b);
    scanf("%lf", &c);
    d = pow(b, 2) - 4 * a * c;
    if (d < 0){
      printf ("net korney");
    }
    else{
      x1 = (-b + sqrt(d)) / (2 * a);
      x2 = (-b - sqrt(d)) / (2 * a);
      printf("x1 raven %.2f\n");
      printf("x1 raven %.2f\n");
    }
    printf ("\nnext?");
    char next;
    scanf (" %s", &next);
    if (next =='y' || next == 'Y'){}
    else{
      break;
    }
}
