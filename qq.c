#include <stdio.h>

int main() {
    int a, b, temp;
    
    printf("Введите два числа (a b): ");
    scanf("%d %d", &a, &b);
    
    printf("До обмена: a = %d, b = %d\n", a, b);
    
    temp = a;
    a = b;
    b = temp;
    
    printf("После обмена: a = %d, b = %d\n", a, b);
    return 0;
}
