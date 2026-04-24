#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HISTORY 50

typedef struct {
    double a, b, result;
    char operation;
} Calculation;

Calculation history[MAX_HISTORY];
int history_count = 0;

// Добавление в историю
void add_to_history(double a, double b, char op, double res) {
    if (history_count < MAX_HISTORY) {
        history[history_count].a = a;
        history[history_count].b = b;
        history[history_count].operation = op;
        history[history_count].result = res;
        history_count++;
    }
}

// Показать историю
void show_history() {
    if (history_count == 0) {
        printf("История пуста!\n");
        return;
    }
    
    printf("\n=== История вычислений ===\n");
    for (int i = 0; i < history_count; i++) {
        printf("%d. %.2f %c %.2f = %.2f\n", 
               i + 1,
               history[i].a,
               history[i].operation,
               history[i].b,
               history[i].result);
    }
}

// Сложение
double add(double x, double y) {
    return x + y;
}

// Вычитание
double subtract(double x, double y) {
    return x - y;
}

// Умножение
double multiply(double x, double y) {
    return x * y;
}

// Деление
double divide(double x, double y) {
    if (y == 0) {
        printf("Ошибка: деление на ноль!\n");
        return 0;
    }
    return x / y;
}

// Возведение в степень
double power(double base, double exp) {
    double result = 1.0;
    int int_exp = (int)exp;
    
    if (exp == 0) return 1;
    
    for (int i = 0; i < abs(int_exp); i++) {
        result *= base;
    }
    
    if (exp < 0) {
        result = 1.0 / result;
    }
    
    return result;
}

// Остаток от деления
double modulus(double x, double y) {
    if (y == 0) {
        printf("Ошибка: деление на ноль!\n");
        return 0;
    }
    return (int)x % (int)y;
}

int main() {
    double num1, num2, result;
    char operation;
    int choice;
    
    printf("=== Расширенный калькулятор ===\n");
    
    do {
        printf("\nМеню:\n");
        printf("1. Выполнить операцию\n");
        printf("2. Показать историю\n");
        printf("3. Очистить историю\n");
        printf("4. Выйти\n");
        printf("Выбор: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("\nВведите первый число: ");
                scanf("%lf", &num1);
                printf("Введите оператор (+, -, *, /, ^, %%): ");
                scanf(" %c", &operation);
                printf("Введите второе число: ");
                scanf("%lf", &num2);
                
                switch(operation) {
                    case '+':
                        result = add(num1, num2);
                        printf("Результат: %.2f + %.2f = %.2f\n", num1, num2, result);
                        break;
                    case '-':
                        result = subtract(num1, num2);
                        printf("Результат: %.2f - %.2f = %.2f\n", num1, num2, result);
                        break;
                    case '*':
                        result = multiply(num1, num2);
                        printf("Результат: %.2f * %.2f = %.2f\n", num1, num2, result);
                        break;
                    case '/':
                        result = divide(num1, num2);
                        if (num2 != 0) {
                            printf("Результат: %.2f / %.2f = %.2f\n", num1, num2, result);
                        }
                        break;
                    case '^':
                        result = power(num1, num2);
                        printf("Результат: %.2f ^ %.2f = %.2f\n", num1, num2, result);
                        break;
                    case '%':
                        result = modulus(num1, num2);
                        printf("Результат: %.0f %% %.0f = %.0f\n", num1, num2, result);
                        break;
                    default:
                        printf("Неверный оператор!\n");
                        continue;
                }
                
                add_to_history(num1, num2, operation, result);
                break;
                
            case 2:
                show_history();
                break;
                
            case 3:
                history_count = 0;
                printf("История очищена!\n");
                break;
                
            case 4:
                printf("До свидания!\n");
                break;
                
            default:
                printf("Неверный выбор!\n");
        }
    } while(choice != 4);
    
    return 0;
}
