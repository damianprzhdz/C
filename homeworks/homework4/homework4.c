#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "homework4.h"

int main(int argc, char const *argv[]) {

	int try;
	double option2;
	char s[MAXVALUE];
	
	while ((try = getop(s)) != EOF) {
		switch (try) {
			case NUM: push(atof(s)); 
                break;

			case '+': push(pop() + pop()); 
                break;

			case '*': push(pop() * pop());
                break;

			case '-': option2 = pop(); push(pop() - option2); 
                break;

			case '/': option2 = pop(); 
				if (option2 != 0.0) 
					push(pop() / option2); 
				else
					printf("caution: divizor is zero\n"); 
                break;

			case '%': option2 = pop(); 
				if (option2 != 0.0) 
					push((int)pop() % (int)option2); 
				else
					printf("caution: divizor is zeror\n"); 
                break;

			case '\n': printf("      =\t%.9g\n", pop()); 
                break;

			default: if(strlen(s) > 1 && (s[0] != 'a' && s[1] != 'n' && s[2] != 's'))
				printf("caution: unknown command %s\n", s); 
            break;

		}
	}
	return back;
}
