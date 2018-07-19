// Sample code in <Beginning Algorithm Contest (2nd)>
// uva 297 quadtree
// ACCEPTED on 20180628

#include <stdio.h>
#include <string.h>

#define MAXP 32
#define MAXL 1365	// 4^5 + 4^4 + .. + 1

int pixels[MAXP + 2][MAXP + 2], cnt;
char qtree[MAXL + 1];
int ind;
int draw(int, int, int);

int
main()
{
	int	c;

	scanf("%d", &c);
	while (c--) {
		memset(pixels, 0, sizeof(pixels));
		cnt = 0;
		scanf("%s", qtree), ind = 0;	// tree 1
		draw(1, 1, MAXP);
		scanf("%s", qtree), ind = 0;	// tree 2
		draw(1, 1, MAXP);
		printf("There are %d black pixels.\n", cnt);
	}

	return 0;
}
 
// [1][2]
// [3][4]
// the amount of black pixels is no matter of the way of partition
int
draw(int row, int col, int wdt) // row, column, width
{
	char	ch;
	int	i, j;

	ch = qtree[ind++];
	if (ch == 'f') {
		for (i = row; i < row + wdt; ++i)
			for (j = col; j < col + wdt; ++j)
				if (pixels[i][j] == 0) {
					pixels[i][j] = 1;	// 1 means black
					cnt++;
				}
	} else if (ch == 'p') {
		draw(row, col, wdt / 2);
		draw(row, col + wdt / 2, wdt / 2);
		draw(row + wdt / 2, col, wdt / 2);
		draw(row + wdt / 2, col + wdt / 2, wdt / 2);
	}
	// if ch == 'e', do nothing

	return 0;
}
