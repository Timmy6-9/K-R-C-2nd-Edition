#include <stdio.h>

#define MAX 1000 // Max input length
#define THRESH 80 // Threshold input length (Line should be printed if over this number)

int testline(char line[], int maxlen);

int main(){

    int currlen;

    char line[MAX];

    while((currlen = testline(line, MAX)) > 0){
        if(currlen > THRESH){
            printf("%s\n", line);
        }
    }
    return 0;
}

// Change getl to testline, which now tests if a string is over 80 characters, if it is, print it
int testline(char line[], int maxlen){

    int c, i;

    for(i=0; (c=getchar()) != EOF && c!='\n'; ++i){
        if(i < maxlen - 1 && c != TAB)
            line[i] = c;
    }
    if(c == '\n'){
        line[i] = c;
        ++i;
    }
    line[i] = '\0';

    return i;
}