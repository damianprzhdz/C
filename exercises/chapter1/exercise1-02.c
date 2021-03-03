#include <stdio.h>

int main()
{
    printf("Hello, world\e"); //Sequence escape character
    printf("Hello, world\b"); // Backspace
    printf("Hello, world\v"); // Vertical Tab

    return 0;
}
