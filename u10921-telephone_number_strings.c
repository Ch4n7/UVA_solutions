#include <stdio.h>

#define MAXLINE 32

char buff[MAXLINE];

int
main()
{
	int	i;

	while (fgets(buff, MAXLINE, stdin) != NULL) {
		i = 0;
		while (buff[i] != '\0') {
			switch (buff[i]) {
				case 'A':
				case 'B':
				case 'C':
					putchar('2');
					break;
				case 'D':
				case 'E':
				case 'F':
					putchar('3');
					break;
				case 'G':
				case 'H':
				case 'I':
					putchar('4');
					break;
				case 'J':
				case 'K':
				case 'L':
					putchar('5');
					break;
				case 'M':
				case 'N':
				case 'O':
					putchar('6');
					break;
				case 'P':
				case 'Q':
				case 'R':
				case 'S':
					putchar('7');
					break;
				case 'T':
				case 'U':
				case 'V':
					putchar('8');
					break;
				case 'W':
				case 'X':
				case 'Y':
				case 'Z':
					putchar('9');
					break;
				default:
					putchar(buff[i]);
			}
			++i;
		}
	}

	return 0;
}
