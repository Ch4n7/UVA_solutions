#include <stdio.h>

int
main()
{
	int	n, i, a, b,
		sum, diff;

	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%d%d", &sum, &diff);
		if ((sum + diff) % 2 == 0) {	// a, b must be integers
			a = (sum + diff) / 2;
			b = sum - a;
			if (b >= 0) {		// a, b must be greater than 0
				printf("%d %d\n", a, b);
				continue;
			}
		}
		printf("impossible\n");
	}

	return 0;
}
