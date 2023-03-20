#include <stdio.h>

// Define whitespace as constants

#define BLANK ' '
#define NEWLINE '\n'
#define TAB '\t'

// Exercise is to output a histogram of different word lengths, I'm going to cap it at 10 letter words and the frequency at 10 words.

int main(){

    int i, x, c;

    // Declare array of 9 integers, 1 for each number 1 - 9
    int digits[9];
    // Another array for each a - z character and an extra for whitespace characters
    int chars[27];

    // Initialize both arrays
    for(i = 0; i < 9; i++)
        digits[i] = 0;

    for(i = 0; i < 27; i++)
        chars[i] = 0;

    // I'm aware that there are libraries out there that will capitalize characters etc but that doesn't really fit with the spirit of the exercise
    while((c = getchar()) != EOF){
        if(c < 58 && c > 32 && (c >= '1' || c <= '9')){
            ++digits[c - '1'];
        }
        else if(c < 91 && c > 64 && (c >= 'A' || c <= 'Z'))
            // Array index is the current character minus 'A' (65), this works as all of these characters are in order
            ++chars[c - 'A'];
        else if(c < 123 && c > 96 && (c >= 97 || c <= 122))
            //lowercase characters are treated just the same but lowercase 'a' (97) is taken away for the array index
            ++chars[c - 'a'];
        else if(c == TAB || c == NEWLINE || c == BLANK)
            //Whitespace characters are added to the end of the chars array
            ++chars[26];
    }

    // Bars need to be built during the for loop, as does the graph
    // print tabs, labels and graph edge, then number of required hash symbols, then finally add a newline.
    for(i = 20; i > 0; i--){

        if(i == 10)
            printf("Frequency\b\b");
        if(i >= 10)
            printf("\t\t\b%d|", i);
        else
            printf("\t\t%d|", i);

        // Either 2 spaces if not occupied or 1 space, 1 hash symbol if it is
        for(x = 0; x < 9; x++)
            if(digits[x] >= i)
                printf("# ");
            else
                printf("  ");

        // Next, do the same for the chars array
        for(x = 0; x <= 26; x++)
            if(chars[x] >= i)
                printf("# ");
            else
                printf("  ");

        printf("\n");
    }

    printf("\t\t  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");

    printf("\t\t  1 2 3 4 5 6 7 8 9 A B C D E F G H I J K L M N O P Q R S T U V W X Y Z WS \n");

    printf("\n\t\t\t\t\t\tCharacter\n");
}