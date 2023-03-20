#include <stdio.h>

// This program needs a function that reverses the input line-by-line

#define MAX 1000 // Max input length

int getl(char line[], int maxlen);

char * reverse(char s[], int length);

int main(){

    int currlen;

    char line[MAX];

    while((currlen = getl(line, MAX)) > 0){
        printf("%s\n", reverse(line, currlen));
    }

    return 0;
}

// Change getl to testline, which now tests if a string is over 80 characters, if it is, print it
int getl(char line[], int maxlen){

    int c, i;

    for(i=0; (c=getchar()) != EOF && c!='\n'; ++i){
        if(i < maxlen - 1)
            line[i] = c;
    }
    if(c == '\n'){
        line[i] = c;
        ++i;
    }
    line[i] = '\0';

    return i;
}

char * reverse(char s[], int length){

    int i, n;

    char c, d;

    n = 0;

    for(i = length; i > n; --i){

        c = s[i - 1];
        d = s[n];

        s[i - 1] = d;
        s[n] = c;

        ++n;
    }

    return s;
}