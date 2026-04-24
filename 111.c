#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BOOKS 100
#define MAX_TITLE 100
#define MAX_AUTHOR 50

// Структура для хранения информации о книге
typedef struct {
    int id;
    char title[MAX_TITLE];
    char author[MAX_AUTHOR];
    int year;
    int is_borrowed; // 0 - доступна, 1 - выдана
} Book;

Book library[MAX_BOOKS];
int book_count = 0;

// Добавление новой книги
void add_book() {
    if (book_count >= MAX_BOOKS) {
        printf("Библиотека переполнена!\n");
        return;
    }
    
    Book new_book;
    new_book.id = book_count + 1;
    
    printf("Введите название книги: ");
    getchar(); // очистка буфера
    fgets(new_book.title, MAX_TITLE, stdin);
    new_book.title[strcspn(new_book.title, "\n")] = 0;
    
    printf("Введите автора: ");
    fgets(new_book.author, MAX_AUTHOR, stdin);
    new_book.author[strcspn(new_book.author, "\n")] = 0;
    
    printf("Введите год издания: ");
    scanf("%d", &new_book.year);
    
    new_book.is_borrowed = 0;
    
    library[book_count] = new_book;
    book_count++;
    
    printf("Книга успешно добавлена! ID: %d\n", new_book.id);
}

// Показать все книги
void show_books() {
    if (book_count == 0) {
        printf("Библиотека пуста!\n");
        return;
    }
    
    printf("\n=== Список всех книг ===\n");
    for (int i = 0; i < book_count; i++) {
        printf("ID: %d | Название: %s | Автор: %s | Год: %d | Статус: %s\n",
               library[i].id,
               library[i].title,
               library[i].author,
               library[i].year,
               library[i].is_borrowed ? "Выдана" : "Доступна");
    }
}

// Поиск книги по названию
void search_book() {
    char search_title[MAX_TITLE];
    printf("Введите название книги для поиска: ");
    getchar();
    fgets(search_title, MAX_TITLE, stdin);
    search_title[strcspn(search_title, "\n")] = 0;
    
    int found = 0;
    for (int i = 0; i < book_count; i++) {
        if (strstr(library[i].title, search_title) != NULL) {
            printf("Найдено: %s - %s (%d)\n", library[i].title, library[i].author, library[i].year);
            found = 1;
        }
    }
    
    if (!found) {
        printf("Книга не найдена!\n");
    }
}

// Выдать книгу читателю
void borrow_book() {
    int id;
    printf("Введите ID книги для выдачи: ");
    scanf("%d", &id);
    
    for (int i = 0; i < book_count; i++) {
        if (library[i].id == id) {
            if (library[i].is_borrowed) {
                printf("Книга уже выдана!\n");
            } else {
                library[i].is_borrowed = 1;
                printf("Книга \"%s\" выдана читателю!\n", library[i].title);
            }
            return;
        }
    }
    printf("Книга с ID %d не найдена!\n", id);
}

// Вернуть книгу
void return_book() {
    int id;
    printf("Введите ID книги для возврата: ");
    scanf("%d", &id);
    
    for (int i = 0; i < book_count; i++) {
        if (library[i].id == id) {
            if (!library[i].is_borrowed) {
                printf("Книга и так в библиотеке!\n");
            } else {
                library[i].is_borrowed = 0;
                printf("Книга \"%s\" возвращена!\n", library[i].title);
            }
            return;
        }
    }
    printf("Книга с ID %d не найдена!\n", id);
}

int main() {
    int choice;
    
    printf("=== Система управления библиотекой ===\n");
    
    do {
        printf("\nМеню:\n");
        printf("1. Добавить книгу\n");
        printf("2. Показать все книги\n");
        printf("3. Поиск книги\n");
        printf("4. Выдать книгу\n");
        printf("5. Вернуть книгу\n");
        printf("6. Выход\n");
        printf("Выберите действие: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: add_book(); break;
            case 2: show_books(); break;
            case 3: search_book(); break;
            case 4: borrow_book(); break;
            case 5: return_book(); break;
            case 6: printf("До свидания!\n"); break;
            default: printf("Неверный выбор!\n");
        }
    } while(choice != 6);
    
    return 0;
}
