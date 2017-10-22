#include <stdio.h>
#include <string.h>
#define MAXN 1000007


int
main()
{
	int	l, r, ll, rr,
		max, i, len,
		cl[MAXN]; /*cycle length record*/
	long long	n;// n may exceed 'int' during the interim process 

	memset(cl, 0, sizeof(cl));
	while (scanf("%d%d", &l, &r) == 2) {
		if (l > r) {	// It is possible that l > r. Keep the order.
			ll = r;
			rr = l;
		} else {
			ll = l;
			rr = r;
		}
		max = 0;
		for (i = ll; i <= rr; ++i) {
			n = i;
			len = 1;
			while (n != 1) {
				if (n < MAXN && cl[n] > 0) {
					len += cl[n] - 1;
					break;
				}
				if (n % 2)
					n = 3 * n + 1;
				else
					n = n / 2;
				++len;
			}
			cl[i] = len;
			if (cl[i] > max)
				max = cl[i];
		}
		printf("%d %d %d\n", l, r, max);
	}
}

