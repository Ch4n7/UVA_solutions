#include <stdio.h>

int
main()
{
	int	i, j, k, cas, dep, ind;	// cases, depth, index

	scanf("%d", &cas);
	for (i = 1; i <= cas; ++i) {
		scanf("%d%d", &dep, &ind);
		k = 1;
		for (j = 1; j < dep; ++j) { //  switch from 1 to D-1
			if (ind % 2) {
				k = 2 * k;
				ind = ind / 2 + 1;
			} else {
				k = 2 * k + 1;
				ind = ind / 2;
			}
		}
		printf("%d\n", k);
	}

	return 0;

}
