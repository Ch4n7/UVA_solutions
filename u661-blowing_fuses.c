#include <stdio.h>
#include <string.h>
#define MAXN 21

int cons[MAXN], state[MAXN];

int
main()
{
	int	n, m, c, op, 
		k, i, cur, max;
	k = 1;
	while (scanf("%d%d%d", &n, &m, &c) == 3 &&
		!((n == 0) && (m == 0) && (c == 0))) {
		memset(cons, 0, sizeof(cons));
		for (i = 1; i <= n; ++i)
			scanf("%d", cons + i);
		max = cur = 0;
		memset(state, 0, sizeof(state));
		for (i = 0; i < m; ++i) {
			scanf("%d", &op);
			if (state[op]) {
				cur -= cons[op];
				state[op] = 0;
			} else {
				cur += cons[op];
				if (cur > max) max = cur;
				state[op] = 1;
			}
		}
		printf("Sequence %d\n", k++);
		if (max > c)
			printf("Fuse was blown.\n\n");
		else {
			printf("Fuse was not blown.\n");
			printf("Maximal power consumption was %d amperes.\n\n",max);
		}
	}

	return 0;
}
