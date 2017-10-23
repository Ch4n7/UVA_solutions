#include <stdio.h>
#include <string.h>
#define MAXN 501

int board[MAXN][MAXN];

int
main()
{
	int	w, h, n, empty, // width, height, number
		x1, y1, x2, y2,
		i, r, c, tmp;

	while (scanf("%d%d%d", &w, &h, &n) == 3 &&
			!((w == 0) && (h == 0) && (n == 0))) {
		memset(board, 0, sizeof(board));
		empty = w * h;
		for (i = 0; i < n; ++i) {
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			if (x2 < x1) {		// set x1 the min of x1, x2
				tmp = x1;
				x1 = x2;
				x2 = tmp;
			}
			if (y2 < y1) {		// set y1 the min of y1, y2
				tmp = y1;
				y1 = y2;
				y2 = tmp;
			}
			for (r = x1; r <= x2; ++r)
				for (c = y1; c <= y2; ++c)
					if (!board[r][c]) {	// if never visited
						--empty;
						board[r][c] = 1;
					}
		}
		if (empty == 0)		// note that three different output situations
			printf("There is no empty spots.\n");
		else if (empty == 1)
			printf("There is one empty spot.\n");
		else
			printf("There are %d empty spots.\n", empty);
	}

	return 0;
}	
