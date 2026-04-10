#include <stdio.h>

int main() {
    char ch;
    int shift = 3;
    
    printf("Введите строку: ");
    
    while ((ch = getchar()) != '\n') {
        if (ch >= 'a' && ch <= 'z') {
            ch = ((ch - 'a' + shift) % 26) + 'a';
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = ((ch - 'A' + shift) % 26) + 'A';
        }
        putchar(ch);
    }
    printf("\n");
    
    return 0;
}
