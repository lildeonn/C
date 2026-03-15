#include <stdio.h>

int main(){
	int first, second;
	
	printf("vvedite pervoe chislo: ");
	scanf("%d", &first);
	
	printf("vvedite vtoroe chislo: ");
	scanf("%d", &second);
	
	printf("\nsumma: %d\n", first+second);
	printf("raznost: %d\n", first-second);
	printf("umnozhenie: %d\n", first*second);
	printf("delenie (celoe): %d\n", first/second);
	printf("ostatok: %d\n", first%second);
	
	return 0;
}
