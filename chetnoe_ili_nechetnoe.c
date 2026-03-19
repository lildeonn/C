#include <stdio.h>

int main(){
	int number;
	char danet;
	while(1){
		
		printf("vvedite chislo: ");
		scanf("%d", &number);
			
		if(number % 2 == 0){
			printf("\nchislo %d : chetnoe", number);
		}
		else{
			printf("\nchislo %d : nechetnoe\n", number);
		}
		do{
			printf("\nhotite prodolzhit? (y/n)\n");
			scanf("%s", &danet);
			
			if (danet != 'y' && danet != 'Y' && danet != 'n' && danet != 'N') {
                printf("nevernaya bekva, poprobuyte eshe raz.\n");
            }
			
		}while(danet != 'y' && danet != 'Y' && danet != 'n' && danet != 'N');
		
		if(danet == 'n' || danet == 'N'){
				break;
		}
		
	}
	return 0;
}
