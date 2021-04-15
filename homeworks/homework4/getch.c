#include <stdio.h>
#include "homework4.h"

char buffering[BUFSIZE];
int bufp = 0;
int getch(void)
{
    return (bufp > 0) ? buffering[--bufp] : getchar();
}

void ungetch(int c)
{
    if(bufp >= BUFSIZE) {
        printf("ungetch: There are too many characters\n");
    } else {
        buffering[bufp++] = c; 
    }
    return back;
}