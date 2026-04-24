#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 15
#define MAX_TRIES 10

char words[][20] = {"ПРОГРАММИРОВАНИЕ", "КОМПЬЮТЕР", "РАЗРАБОТЧИК", "АЛГОРИТМ", "ФУНКЦИЯ"};
char hidden[30];
char guessed_letters[26];
int guessed_count = 0;

void initialize_game(int word_index) {
    int length = strlen(words[word_index]);
    for (int i = 0; i < length; i++) {
        hidden[i] = '_';
    }
    hidden[length] = '\0';
    guessed_count = 0;
}

void display_game(char word[]) {
    printf("\nСлово: ");
    for (int i = 0; i < strlen(word); i++) {
        printf("%c ", hidden[i]);
    }
    printf("\n");
    
    printf("Угаданные буквы: ");
    for (int i = 0; i < guessed_count; i++) {
        printf("%c ", guessed_letters[i]);
    }
    printf("\n");
}

int is_letter_guessed(char letter) {
    for (int i = 0; i < guessed_count; i++) {
        if (guessed_letters[i] == letter) {
            return 1;
        }
    }
    return 0;
}

int update_word(char word[], char letter) {
    int found = 0;
    for (int i = 0; i < strlen(word); i++) {
        if (word[i] == letter) {
            hidden[i] = letter;
            found = 1;
        }
    }
    return found;
}

int is_word_complete() {
    for (int i = 0; i < strlen(hidden); i++) {
        if (hidden[i] == '_') {
            return 0;
        }
    }
    return 1;
}

void draw_hangman(int mistakes) {
    printf("\n");
    printf("  +---+\n");
    printf("  |   |\n");
    printf("  %s   |\n", mistakes >= 1 ? "O" : " ");
    printf(" %s%s%s  |\n", mistakes >= 3 ? "/" : " ", mistakes >= 2 ? "|" : " ", mistakes >= 4 ? "\\" : " ");
    printf(" %s %s  |\n", mistakes >= 5 ? "/" : " ", mistakes >= 6 ? "\\" : " ");
    printf("      |\n");
    printf("==========\n");
}

int main() {
    srand(time(NULL));
    int word_index = rand() % 5;
    char word[20];
    strcpy(word, words[word_index]);
    
    initialize_game(word_index);
    int mistakes = 0;
    char guess;
    int game_over = 0;
    
    printf("=== ИГРА ВИСЕЛИЦА ===\n");
    printf("Угадайте слово! У вас %d попыток.\n", MAX_TRIES);
    
    while (!game_over) {
        display_game(word);
        draw_hangman(mistakes);
        
        printf("Введите букву: ");
        scanf(" %c", &guess);
        guess = toupper(guess);
        
        if (is_letter_guessed(guess)) {
            printf("Вы уже угадывали эту букву!\n");
            continue;
        }
        
        guessed_letters[guessed_count] = guess;
        guessed_count++;
        
        if (update_word(word, guess)) {
            printf("Отлично! Буква '%c' есть в слове!\n", guess);
            if (is_word_complete()) {
                printf("\nПОЗДРАВЛЯЮ! Вы угадали слово: %s\n", word);
                game_over = 1;
            }
        } else {
            mistakes++;
            printf("Увы! Буквы '%c' нет в слове. Осталось попыток: %d\n", guess, MAX_TRIES - mistakes);
            if (mistakes >= MAX_TRIES) {
                draw_hangman(mistakes);
                printf("\nИГРА ОКОНЧЕНА! Вы проиграли.\n");
                printf("Загаданное слово было: %s\n", word);
                game_over = 1;
            }
        }
    }
    
    printf("\nСпасибо за игру!\n");
    return 0;
}
