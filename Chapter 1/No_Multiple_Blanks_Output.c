#include <stdio.h>

#define BLANK ' '

int main(){

int c, lastChar;

    while((c = getchar()) != EOF){
        if(c == BLANK && lastChar != BLANK){
            putchar(c);
            lastChar = c;
        }
        else if(c != BLANK){
            putchar(c);
            lastChar = c;
        }
    }
}