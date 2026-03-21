#include <stdio.h>

int main(){

	int i;
	char str[81];
	scanf("%80[^\n]", str);

	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] >= 'a' && str[i] <= 'b'){
			str[i] -= 'a' - 'A';
		}
		if (str[i] == '!'){
			str[i] = '?';
		}
	}
		
	printf("%s\n", str);
	return 0;
}
