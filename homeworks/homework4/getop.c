#include <stdio.h>
#include <ctype.h>
#include "homework4.h"

int getop(char s[])
{
    int i;
    int c;

    while((s[0] = c = getch()) == ' ' 
        || c == '\t' != EOF);
    s[1] = '\0';

    i = 0;
    if(!isdigit(c) && c != '.' && c != '-') {
        if (!isalpha(c))
            return c; 
        if (isalpha(c)){
            return tolower(c);
        }
    }

    if(c == '-')
        if(isdigit(c=getch()) 
            || c == '.')
            s[++i]=c;
        else
        {
            if(c!=EOF)
                ungetch(c);
            return '-';
        }

    if(isdigit(c))
        while(isdigit(s[++i] = c = getch()));

    if(c == '.')
        while(isdigit(s[++i] = c = getch()));

    s[i] = '\0';
    if(c != EOF)
        ungetch(c);
    return NUM;
}