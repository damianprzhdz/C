#include <stdio.h> 
/*
int main() {
    int c;
    int EOF = 0;

    while ((c = getchar()) != EOF)
        putchar(c);
}
*/
int main()
{
   char value;
   int c;
   value = ((c = getchar()) != EOF);
   printf("%i\n", value);
   return 0;
}