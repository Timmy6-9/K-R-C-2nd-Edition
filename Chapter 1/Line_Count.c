#include <stdio.h>

int main(){
    // c is the character, nl is number of newlines, tb is number of tabs, bl is number of blanks
    int c, nl, tb, bl;

    nl = 0;
    tb = 0;
    bl = 0;

    while((c = getchar()) != EOF)
        switch(c){
            case '\n':
                ++nl;
                break;
            case '\t':
                ++tb;
                break;
            case ' ':
                ++bl;
                break;
        }

    printf("New lines: %d\n", nl);
    printf("Tabs: %d\n", tb);
    printf("Blanks: %d\n", bl);

}