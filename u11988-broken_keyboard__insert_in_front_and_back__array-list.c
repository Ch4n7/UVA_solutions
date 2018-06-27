// 2018-06-14
// uva 11988, ACCEPTED
// Keywords: linked list using array implementation

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
				default:	// insert the node i from cur position
					next[i] = next[cur];
					next[cur] = i;
					if (cur == tail) tail = i; // update tail if tail changes
					cur = i; // update cur
			}
		}

		for (i = head; i != tail; i = pos) { // visit the linked list from head to tail
			pos = next[i];
			printf("%c", input[pos]);	
		}
		printf("\n");
	}

	return 0;
}
