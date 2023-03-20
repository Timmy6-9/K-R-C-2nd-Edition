#include <stdio.h>

#define TAB '\t'
#define BACKSPACE '\b'
#define BACKSLASH '\\'

// An extra backslash is all that's needed to escape the escape sequence characters

int main(){

    char c;

    while((c = getchar()) != EOF){
        switch (c)
        {
        case TAB:
            printf("\\t");
            break;
        case BACKSPACE:
            printf("\\b");
            break;
        case BACKSLASH:
            printf("\\");
            break;
        default:
            putchar(c);
            break;
        }
    }
}