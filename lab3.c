#include <stdio.h>

int main(){

	int i;
	char str[81];
	scanf("%80s[^\n]", str);

	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] >= 'a' && str[i] <= 'b'){
			str[i] -= 'a' - 'A';
		}
	}
		
	printf("%s\n", str);
	return 0;
}
