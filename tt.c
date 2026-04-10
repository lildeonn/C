#include <stdio.h>

int main() {
    int x, y, z, max;
    
    printf("Введите три числа: ");
    scanf("%d %d %d", &x, &y, &z);
    
    max = x;
    if (y > max) max = y;
    if (z > max) max = z;
    
    printf("Максимальное число: %d\n", max);
    return 0;
}
