#include <stdio.h>

int main() {
    int n, sum = 0;
    
    printf("Введите число N: ");
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    
    printf("Сумма чисел от 1 до %d = %d\n", n, sum);
    return 0;
}
