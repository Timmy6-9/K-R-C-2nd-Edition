#include <stdio.h>

// UNIX has 8 characters every tab stop
#define BIG 10000
#define TAB '\t'
#define BLANK ' '
#define CHARSPERTAB 8

int getinput(char string[], int length);

void entab(char string[], int max);

// Replace blanks with required number of tabs/blanks

int main(){

    int length;

    char input[BIG];

    length = 0;
    // Keeps repeating get input as length is always 1
    while((length = getinput(input, BIG)) > 0){
        entab(input, length);
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

// Need to iterate through string array, count number of blanks until next non-blank character, replace them, add to the main iterating number to skip as necessary then continue iterating.

void entab(char string[], int length){

    int i, n, x, replacechars, nexttabstop;

    // Start at 7 as the array starts at 0
    nexttabstop = 7;

    // Array of 1s and 0s, if 1, need to replace blank, if 0 don't replace.
    replacechars = 0;

    for(i = 0; i < length; ++i){
        if(string[i] == BLANK){
            ++replacechars;
            // Another for loop, keep i value the same
            for(n = i + 1; n < length; ++n)
                if(string[n] == BLANK)
                    ++replacechars;
                else
                    break;
        }

    if(replacechars > 0)
        printf("Characters to replace: %d\n", replacechars);

    // If it's higher than 0 and reaches the nexttabstop threshold, do stuff with replacechars
    if(replacechars > 0 && replacechars + i >= nexttabstop){
        for(n = i; n < (i + replacechars - 1); ++n){
            if(n != nexttabstop){
                string[n] = string[n + 1];
                string[n + 1] = BLANK;
            }
            else{
                string[n] = TAB;
                nexttabstop += 8;
            }
        }
    }

    i = i + replacechars;
    replacechars = 0;
    }
}