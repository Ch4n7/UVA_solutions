#include <stdio.h>
#include <string.h>
#define MAX_LINE 100000

char input[MAX_LINE + 1];
int next[MAX_LINE + 1];

int
main()
{
	int	i, head, tail, cur, pos;

	while (scanf("%s", input  + 1) == 1) {
		head = tail = 0; 
		cur = 0;
		next[cur] = 0;	// can be anything that not point the input[1..n]

		for (i = 1; i <= strlen(input + 1); ++i) {
			switch (input[i]) {
				case '[':
					cur = head;	// head always point to input[0]
					break;
				case ']':
					cur = tail;
					break;
				default:
					next[i] = next[cur];
					next[cur] = i;
					if (cur == tail) tail = i;
					cur = i;
			}
		}

		for (i = head; i != tail; i = pos) {
			pos = next[i];
			printf("%c", input[pos]);	
		}
		printf("\n");
	}

	return 0;
}
