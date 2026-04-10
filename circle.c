#include <stdio.h>
#define PI 3.14159

int main() {
    float radius, area;
    
    printf("Введите радиус круга: ");
    scanf("%f", &radius);
    
    area = PI * radius * radius;
    
    printf("Площадь круга: %.2f\n", area);
    return 0;
}
