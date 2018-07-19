#include <stdio.h>
#include <string.h>
#define MAX 128

int m, n;
char grids[MAX][MAX];
int idx[MAX][MAX];
int floodfill(int, int, int);

int
main()
{
	int	i, j, cnt;

	while (scanf("%d%d", &m ,&n) == 2
			&& m != 0) {
		for (i = 0; i < m; ++i)
			scanf("%s", grids[i]);
		cnt = 0;
		memset(idx, 0, sizeof(idx));
		for (i = 0; i < m; ++i)
			for (j = 0; j < n; ++j)
				if (grids[i][j] == '@' && idx[i][j] == 0)
					floodfill(i, j, ++cnt);
		printf("%d\n", cnt);
	}

	return 0;
}

int
floodfill(int row, int col, int id)
{
	int	dr, dc;

	if (row < 0 || row >= m || col < 0 || col >= n)	// bounds
		return -1;
	if (grids[row][col] != '@' || idx[row][col] != 0) // cases that shouldn't be colored
		return -1;

	// first, fill the base unit
	idx[row][col] = id;

	// then, extend to fill in 8 directions
	for (dr = -1; dr <= 1; ++dr)
		for (dc = -1; dc <= 1; ++dc)
			if (dr != 0 || dc != 0)
				floodfill(row + dr, col + dc, id);

	return 0;
}
