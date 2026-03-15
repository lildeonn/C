#include <stdio.h>

int main(){
	int first, second;
	char next;
	
	while(1 == 1){
		
		printf("vvedite pervoe chislo: ");
		scanf("%d", &first);
		
		printf("vvedite vtoroe chislo: ");
		scanf("%d", &second);
		
		printf("\nsumma: %d\n", first+second);
		printf("raznost: %d\n", first-second);
		printf("umnozhenie: %d\n", first*second);
		printf("delenie (celoe): %d\n", first/second);
		printf("ostatok: %d\n", first%second);
		
		do {
            printf("\nprodolzhit? (y/n): ");
            scanf(" %c", &next);  //probel pered %c chtobi iskluchit sluchaynie probeli

            if (next != 'y' && next != 'Y' && next != 'n' && next != 'N') {
                printf("neverniy otvet! poprobuyte eshe raz.\n");
            }
        } while (next != 'y' && next != 'Y' && next != 'n' && next != 'N');

        if (next == 'n' || next == 'N') {
            break;
        }
	}
	return 0;
}
