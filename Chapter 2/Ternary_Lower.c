#include <stdio.h>

#define MAXLEN 1000

int lower(char string[]);

int main(){

    char string[MAXLEN];

    printf("Enter a string to convert to all lowercase: \n");
    fgets(string, MAXLEN, stdin);

    lower(string);

    printf("%s", string);

    return 0;
}

int lower(char string[]){

    int i;

    for(i = 0; i < MAXLEN; i++){
        // (Conditional expression) ? if true expression : if false expression
        // Convert if uppercase
        (string[i] >= 65 && string[i] <= 90) ? string[i] += 32 : ' ';
        // break if end of string or newline character is found
        (string[i] == '\n' || string[i] == '\0') ? i = MAXLEN : ' ';
    }

    return 0;
}