#include <stdio.h>

int main(){
	int chislo, i;
	char prod;
	while (1){
		printf("vvedite chislo: ");
		scanf("%d", &chislo);
		for(i = 0; i < 10; i++){
			printf("%d x %d = %d\n", chislo, i + 1, chislo * (i+1));
		}
		do{
			printf("\nprodolzhit? (y/n) ");
			scanf("%s", &prod);
			if (prod != 'y' && prod != 'Y' && prod != 'n' && prod != 'N') {
                printf("nuzhno pisat druguyu bukvu!!!!!!!\n");
        	}
		}while (prod != 'y' && prod != 'Y' && prod != 'n' && prod != 'N');
		if(prod == 'n' || prod == 'N'){
			break;
		}
	}
	return 0;
}
