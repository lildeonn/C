#include <stdio.h>

int main(){
	int chislo, i;
	printf("vvedite chislo: ");
	scanf("%d", &chislo);
	for(i = 0; i < 10; i++){
		printf("%d x %d = %d\n", chislo, i + 1, chislo * (i+1));
	}
	
	return 0;
}
