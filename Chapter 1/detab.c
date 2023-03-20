#include <stdio.h>

// UNIX has 8 characters every tab stop
#define BIG 10000
#define TAB '\t'
#define BLANK ' '
#define CHARSPERTAB 8

int getinput(char string[], int length);

void detab(char string[], int max);

// Replace tabs/tab stops with the correct number of spaces to the next tab stop
int main(){

    int length = 0;

    char input[BIG];

    while((length = getinput(input, BIG)) > 0){
        detab(input, length);
        printf("%s", input);
        length = 0;
    }

    return 0;
}

int getinput(char string[], int max){

    int i, n, c, spacestofill;

    for(i = 0; (c = getchar()) != EOF && c != '\n' && i < max; ++i)
        string[i] = c;

    if(c = '\n'){
        string[i] = c;
        ++i;
    }

    string[i] = '\0';

    return i;
}

void detab(char string[], int length){

    int i, n, spacestofill;

    // Find and replace tabs with required spaces
    for(i = 0; i < length; ++i){
        if(string[i] == TAB){
            // Add multiples of 8 until higher than i, then subtract i for the number of spaces to fill
            if(i < CHARSPERTAB + 1){
                spacestofill = (CHARSPERTAB - i);
                // i is where to insert blanks, spacestofill is how many blanks to insert
                for(n = i; n < spacestofill; ++n){
                    string[n + 1] = string[n];
                    string[n] = BLANK;
                }
            }
            else{
                for(n = 0; n < CHARSPERTAB + 1; n+=CHARSPERTAB)
                    ;
                spacestofill =  (n - i);
                for(n = i; n < spacestofill; ++n){
                    string[n + 1] = string[n];
                    string[n] = BLANK;
                }
            }
        }
    }
}