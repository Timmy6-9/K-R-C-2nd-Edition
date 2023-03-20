#include <stdio.h>
#define MAX 1000

int getl(char line[], int maxlen);
void copy(char to[], char from[]);

int main(){

    int currlen;
    int currmax = 0;

    char line[MAX];
    char longest[MAX];

    while((currlen = getl(line, MAX)) > 0){
        if(currlen > currmax){
            currmax = currlen;
            copy(longest, line);
        }
    }
    if(currmax > 0)
        printf("%d\n%s\n", currmax, longest);
    return 0;
}

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

void copy(char to[], char from[]){

    int i;

    i = 0;
    while((to[i] = from[i]) != '\0')
        ++i;
}