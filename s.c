#include <stdio.h>

int main() {
    int number;
    
    printf("Введите целое число: ");
    scanf("%d", &number);
    
    if (number % 2 == 0) {
        printf("%d - чётное число\n", number);
    } else {
        printf("%d - нечётное число\n", number);
    }
    
    return 0;
}
