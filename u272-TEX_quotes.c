#include <stdio.h>

int
main()
{
	char	ch;
	int	state;

	state = 0;
	while (~scanf("%c", &ch)) {
		if (ch == '"') {
			if (!state) {
				printf("``");
				state = 1;
			} else {
				printf("''");
				state = 0;
			}
		} else {
			printf("%c", ch);
		}
	}

	return 0;
}
