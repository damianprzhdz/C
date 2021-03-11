#include <stdio.h>
#include <ctype.h> 

#define FIRST 1
#define LAST 0

int main(int argc, char const *argv[]) {
	int c;
	int p, b, br, s, d;
	int ld = LAST;
	p = b = br = s = d = 0;
	int none = 0;


	while((c = getchar()) != EOF) {
		none = 0;
		switch (c) {
			case '(':
				p++;
				break;
			case '[':
				b++;
				break;
			case '{':
				br++;
				break;
			case ')':
				p--;
				break;
			case ']':
				b--;
				break;
			case '}':
				br--;
				break;
			case '\'':
				s = !s;
				break;
			case '\"':
				d = !d;
				break;
			case '.':
			  none = 1;
				break;
			case ',':
				none = 1;
				break;
			case ';':
				none = 1;
				break;
		}
		if (none) {
			continue;
		}
		if ((!p) && (!b) && (!br) && (!s) && (!d)) {
			if (!isdigit(c) && ld == FIRST) {
				putchar('x');
				ld = LAST;
			}
			isdigit(c) ? ld = FIRST : putchar(c);
		}
		else {
			putchar(c);
		}
	}
}