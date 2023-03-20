#include <stdio.h>

#define IN 1 // Typing word
#define OUT 0 // Not Typing word
#define BLANK ' '
#define NEWLINE '\n'
#define TAB '\t'

// Exercise is to output a histogram of different word lengths, I'm going to cap it at 10 letter words and the frequency at 10 words.

int main(){

    int i, x, c, wState, count;

    count = 0;

    wState = OUT;

    // Declare array of 10 integers, one for each length (1 - 10 letter/character words)
    int lwords[10];

    for(i = 0; i < 10; i++)
        lwords[i] = 0;

    while((c = getchar()) != EOF){
        if(c == TAB || c == NEWLINE || c == BLANK){
            wState = OUT;
        }
        else if(wState == OUT)
            wState = IN;

        if(wState == IN){
            ++count;
        }
        else if(wState == OUT){
            if(count >= 1 && count <= 10)
                ++lwords[count - 1];
                count = 0;
        }
    }

    // Bars need to be built during the for loop, as does the graph
    // print tabs, labels and graph edge, then number of required hash symbols, then finally add a newline.
    for(i = 10; i > 0; i--){

        if(i == 5)
            printf("Frequency\b\b");
        if(i == 10)
            printf("\t\t\b%d|", i);
        else
            printf("\t\t%d|", i);

        // Either 2 spaces if not occupied or 1 space, 1 hash symbol if it is
        // Remember that this is vertical, we do the top of each bar for each length before going down to the next frequency
        for(x = 0; x < 10; x++)
            if(lwords[x] >= i)
                printf("# ");
            else
                printf("  ");

        printf("\n");
    }

    printf("\t\t  - - - - - - - - - - \n");
    printf("\t\t  1 2 3 4 5 6 7 8 9 10\n");
    printf("\t\t       Word Length\n");
}