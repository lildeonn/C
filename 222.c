#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SIZE 100

// Заполнение массива случайными числами
void fill_random(int arr[], int n, int min, int max) {
    for (int i = 0; i < n; i++) {
        arr[i] = min + rand() % (max - min + 1);
    }
}

// Вывод массива
void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%4d ", arr[i]);
        if ((i + 1) % 10 == 0) printf("\n");
    }
    printf("\n");
}

// Поиск минимального и максимального
void find_min_max(int arr[], int n, int *min, int *max) {
    *min = arr[0];
    *max = arr[0];
    
    for (int i = 1; i < n; i++) {
        if (arr[i] < *min) *min = arr[i];
        if (arr[i] > *max) *max = arr[i];
    }
}

// Вычисление среднего арифметического
float calculate_average(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return (float)sum / n;
}

// Сортировка пузырьком
void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Нахождение медианы
float find_median(int arr[], int n) {
    int sorted[SIZE];
    for (int i = 0; i < n; i++) {
        sorted[i] = arr[i];
    }
    bubble_sort(sorted, n);
    
    if (n % 2 == 0) {
        return (sorted[n/2 - 1] + sorted[n/2]) / 2.0;
    } else {
        return sorted[n/2];
    }
}

// Подсчёт частоты каждого числа
void frequency_count(int arr[], int n) {
    int counted[SIZE] = {0};
    
    printf("\nСтатистика частоты чисел:\n");
    for (int i = 0; i < n; i++) {
        if (counted[i] == 0) {
            int count = 1;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] == arr[i]) {
                    count++;
                    counted[j] = 1;
                }
            }
            printf("Число %d встречается %d раз(а)\n", arr[i], count);
        }
    }
}

// Поиск простых чисел
int is_prime(int num) {
    if (num <= 1) return 0;
    if (num == 2) return 1;
    if (num % 2 == 0) return 0;
    
    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) return 0;
    }
    return 1;
}

void find_primes(int arr[], int n) {
    printf("\nПростые числа в массиве: ");
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (is_prime(arr[i])) {
            printf("%d ", arr[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("нет");
    }
    printf("\n");
}

int main() {
    int numbers[SIZE];
    int min, max;
    
    srand(time(NULL));
    
    printf("=== Генератор и анализатор чисел ===\n");
    
    // Генерируем массив
    fill_random(numbers, SIZE, 1, 100);
    
    printf("Сгенерированный массив (100 чисел):\n");
    print_array(numbers, SIZE);
    
    // Анализ
    find_min_max(numbers, SIZE, &min, &max);
    float avg = calculate_average(numbers, SIZE);
    float median = find_median(numbers, SIZE);
    
    printf("\n=== Результаты анализа ===\n");
    printf("Минимальное значение: %d\n", min);
    printf("Максимальное значение: %d\n", max);
    printf("Среднее арифметическое: %.2f\n", avg);
    printf("Медиана: %.2f\n", median);
    
    frequency_count(numbers, SIZE);
    find_primes(numbers, SIZE);
    
    // Сортировка
    printf("\nСортировка массива...\n");
    bubble_sort(numbers, SIZE);
    printf("Отсортированный массив:\n");
    print_array(numbers, SIZE);
    
    return 0;
}
