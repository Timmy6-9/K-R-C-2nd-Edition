#include <stdio.h>
#include <string.h>

#define MAX 1000 // Max string length
#define BLANK ' ' // Define blank constant, as I don't want to replace them

// This function needs to delete any character in string1 that matches any character in string2 | For example if string1 is "Henlo" and string 2 is "Hello", string1 should be left as "n"
// I have no idea if capitals and lowercase should match each other but I'll assume they shouldn't as the squeeze function in the book matches the character exactly
int squeeze(char string1[], char string2[]);

int main(){
    char string1[MAX];
    char string2[MAX];

    printf("Please enter string 1: \n");
    fgets(string1, 1000, stdin);

    printf("Please enter string 2: \n");
    fgets(string2, 1000, stdin);

    printf("\n%s%s", string1, string2);

    squeeze(string1, string2);
    
    return 0;
}

int squeeze(char string1[], char string2[]){

    // i is for incrementing string2, n for string1, x is for replacing characters in string 1
    int i, n, x;
    printf("%zu %zu\n", strlen(string1), strlen(string2));

    for(i = 0; i < strlen(string2); ++i)
        for(x = n = 0; x < strlen(string1); ++x)
            if(string2[i] != string1[x] && string2[i] != BLANK && string2[i] >= 'A' && string2[i] <= 'z'){
                string1[n++] = string1[x];
            }
            
    printf("\nNew String:\n%s\n", string1);
}