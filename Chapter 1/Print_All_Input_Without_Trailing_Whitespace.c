#include <stdio.h>

// Remove trailing spaces and tabs from each line then print, if line is blank don't print.

#define MAX 1000 // Max input length
#define TAB '\t' // Tab literal constant
#define NEWLINE '\n' // Newline constant
#define BLANK ' ' // Blank constant

int removeTrailBlanks(char input[], int maxlen);

int main(){

    int strlen;

    char line[MAX];

    while((strlen = removeTrailBlanks(line, MAX)) > 0){
        printf("%s", line);
    }
}

// This function needs to not add newlines if there are no non-whitespace charcters
// It should also take out any tabs or blanks before adding the end of string character

int removeTrailBlanks(char line[], int maxlen){

    int c, i;

    for(i = 0; i < maxlen; i++)
        line[i] = '\0';

    for(i = 0; i < maxlen && (c = getchar()) != EOF; ++i){
        if(c != NEWLINE || (c == NEWLINE && i > 1))
            line[i] = c;
        else if(c == NEWLINE && i < 1)
            line[i] = '\b';
    }

    if(line[i] == TAB || line[i] == BLANK){
        line[i] == '\b';
        ++i;
    }

    line[i] = '\0';

    return i;
}