#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STUDENTS 100
#define MAX_NAME 50
#define MAX_SUBJECTS 5

typedef struct {
    int id;
    char name[MAX_NAME];
    int scores[MAX_SUBJECTS];
    float average;
    char grade;
} Student;

Student students[MAX_STUDENTS];
int student_count = 0;

void calculate_average_and_grade(Student *s) {
    int sum = 0;
    for (int i = 0; i < MAX_SUBJECTS; i++) {
        sum += s->scores[i];
    }
    s->average = sum / (float)MAX_SUBJECTS;
    
    if (s->average >= 90) s->grade = 'A';
    else if (s->average >= 80) s->grade = 'B';
    else if (s->average >= 70) s->grade = 'C';
    else if (s->average >= 60) s->grade = 'D';
    else s->grade = 'F';
}

void add_student() {
    if (student_count >= MAX_STUDENTS) {
        printf("Невозможно добавить больше студентов!\n");
        return;
    }
    
    Student new_student;
    new_student.id = student_count + 1;
    
    printf("Введите имя студента: ");
    getchar();
    fgets(new_student.name, MAX_NAME, stdin);
    new_student.name[strcspn(new_student.name, "\n")] = 0;
    
    printf("Введите оценки по 5 предметам (0-100):\n");
    for (int i = 0; i < MAX_SUBJECTS; i++) {
        printf("Предмет %d: ", i + 1);
        scanf("%d", &new_student.scores[i]);
        while (new_student.scores[i] < 0 || new_student.scores[i] > 100) {
            printf("Оценка должна быть от 0 до 100! Введите снова: ");
            scanf("%d", &new_student.scores[i]);
        }
    }
    
    calculate_average_and_grade(&new_student);
    students[student_count] = new_student;
    student_count++;
    
    printf("Студент добавлен! ID: %d\n", new_student.id);
}

void show_all_students() {
    if (student_count == 0) {
        printf("Нет студентов в базе!\n");
        return;
    }
    
    printf("\n=== ВСЕ СТУДЕНТЫ ===\n");
    for (int i = 0; i < student_count; i++) {
        printf("ID: %d | Имя: %s | Средний балл: %.2f | Оценка: %c\n",
               students[i].id, students[i].name, students[i].average, students[i].grade);
        printf("  Оценки: ");
        for (int j = 0; j < MAX_SUBJECTS; j++) {
            printf("%d ", students[i].scores[j]);
        }
        printf("\n");
    }
}

void show_top_students() {
    if (student_count == 0) {
        printf("Нет студентов!\n");
        return;
    }
    
    Student temp_students[MAX_STUDENTS];
    for (int i = 0; i < student_count; i++) {
        temp_students[i] = students[i];
    }
    
    for (int i = 0; i < student_count - 1; i++) {
        for (int j = 0; j < student_count - i - 1; j++) {
            if (temp_students[j].average < temp_students[j + 1].average) {
                Student temp = temp_students[j];
                temp_students[j] = temp_students[j + 1];
                temp_students[j + 1] = temp;
            }
        }
    }
    
    printf("\n=== ТОП-3 СТУДЕНТА ===\n");
    int top_count = student_count < 3 ? student_count : 3;
    for (int i = 0; i < top_count; i++) {
        printf("%d. %s - Средний балл: %.2f (Оценка: %c)\n",
               i + 1, temp_students[i].name, temp_students[i].average, temp_students[i].grade);
    }
}

void show_failing_students() {
    int found = 0;
    printf("\n=== СТУДЕНТЫ С НЕУДОВЛЕТВОРИТЕЛЬНЫМИ ОЦЕНКАМИ ===\n");
    for (int i = 0; i < student_count; i++) {
        if (students[i].grade == 'F') {
            printf("%s (ID: %d) - Средний балл: %.2f\n",
                   students[i].name, students[i].id, students[i].average);
            found = 1;
        }
    }
    if (!found) {
        printf("Нет студентов с неудовлетворительными оценками!\n");
    }
}

void show_class_statistics() {
    if (student_count == 0) {
        printf("Нет данных!\n");
        return;
    }
    
    float total_average = 0;
    int a_count = 0, b_count = 0, c_count = 0, d_count = 0, f_count = 0;
    
    for (int i = 0; i < student_count; i++) {
        total_average += students[i].average;
        switch(students[i].grade) {
            case 'A': a_count++; break;
            case 'B': b_count++; break;
            case 'C': c_count++; break;
            case 'D': d_count++; break;
            case 'F': f_count++; break;
        }
    }
    
    printf("\n=== СТАТИСТИКА КЛАССА ===\n");
    printf("Всего студентов: %d\n", student_count);
    printf("Средний балл класса: %.2f\n", total_average / student_count);
    printf("Распределение оценок:\n");
    printf("  A (отлично): %d студента(ов)\n", a_count);
    printf("  B (хорошо): %d студента(ов)\n", b_count);
    printf("  C (удовлетворительно): %d студента(ов)\n", c_count);
    printf("  D (плохо): %d студента(ов)\n", d_count);
    printf("  F (неудовлетворительно): %d студента(ов)\n", f_count);
}

int main() {
    int choice;
    
    printf("=== СИСТЕМА УПРАВЛЕНИЯ УСПЕВАЕМОСТЬЮ СТУДЕНТОВ ===\n");
    
    do {
        printf("\nМЕНЮ:\n");
        printf("1. Добавить студента\n");
        printf("2. Показать всех студентов\n");
        printf("3. Показать топ-3 студентов\n");
        printf("4. Показать студентов с 'F'\n");
        printf("5. Показать статистику класса\n");
        printf("6. Выход\n");
        printf("Выберите действие: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: add_student(); break;
            case 2: show_all_students(); break;
            case 3: show_top_students(); break;
            case 4: show_failing_students(); break;
            case 5: show_class_statistics(); break;
            case 6: printf("Программа завершена!\n"); break;
            default: printf("Неверный выбор!\n");
        }
    } while(choice != 6);
    
    return 0;
}
