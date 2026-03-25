#include <stdio.h>

int main() {
    int arr[10];
    int max, max_index;
    int i;
    
    printf("Vvedite 10 chisel:\n");
    for (i = 0; i < 10; i++) {
        printf("Element %d: ", i);
        while (scanf("%d", &arr[i]) != 1) {
            printf("Oshibka! Vvedite celoe chislo: ");
            while (getchar() != '\n');
        }
    }
    
    max = arr[0];
    max_index = 0;
    
    for (i = 1; i < 10; i++) {
        if (arr[i] > max) {
            max = arr[i];
            max_index = i;
        }
    }
    
    printf("\nMassiv: ");
    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    
    printf("\nMaksimalnyy element: %d (index %d)\n", max, max_index);
    
    return 0;
}
