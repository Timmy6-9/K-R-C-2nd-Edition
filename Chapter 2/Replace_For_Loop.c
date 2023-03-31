#include <stdio.h>

#define MAX 100
#define OCTNL '\012' // Octal Newline



int getinput(char string[], int length);

int main(){

    int length;

    char input[MAX];

    // Keeps repeating get input as length is always 1
    while((length = getinput(input, MAX)) > 0){
        printf("%s", input);
        length = 0;
    }

    return 0;
}

int getinput(char string[], int max){

    int i, c;

    // Exercise is to write this for loop without using logical operators (&& or ||)
    // for(i = 0; i < max - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
    //    string[i] = c;

    for(i = 0; (c = getchar()) != '\n'; ++i)
        if(i < max - 1)
            if(c != EOF)
                string[i] = c;

    if(c = '\n'){
        string[i] = c;
        ++i;
    }
    string[i] = '\0';

    return i;
}