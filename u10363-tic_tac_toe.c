#include <stdio.h>
#define SUCC 1
#define FAIL 0
#define YES 1
#define NO 0

char grid[3][3];
int succ(char);

int
main()
{
	char	ignore[4];
	int	n, xn, on,
		i, j, can;

	scanf("%d", &n);
	while (n--) {
		xn = on = 0;
		for (i = 0; i < 3; ++i)
			for (j = 0; j < 3; ++j) {
	// ignore the whitesapce and new line etc. except 'X', 'O', '.'
				while (scanf("%3[^XO.]", ignore));
	// - - - - - -
				scanf("%c", &grid[i][j]);
				switch (grid[i][j]) {
					case 'X':
						++xn; break;
					case 'O':
						++on; break;
				}
			}
		can = NO;		// Since 'X' always go first,
		if (xn == on + 1) {	// the number of 'X' can only be
			can = YES;	// the same as 'O' (the last move
			if (succ('O'))  // is the 'O') or number of 'O'+1
				can = NO;//(the last move is the 'X'). 
		} else if (xn == on) {	// When the last move is the 'O',
			can = YES;	// then 'X' cannot win.
			if (succ('X'))	// When the last move is the 'X',
				can = NO;//then 'O' cannot win.
		} 

		if (can)
			printf("yes\n");
		else
			printf("no\n");
	}

	return 0;
}

int
succ(char ch)
{
	int	k, i, j;

	// horizontal 
	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 3 && grid[i][j] == ch; ++j);
		if (j == 3)
			return SUCC;
	}
	// vertical 
	for (j = 0; j < 3; ++j) {
		for (i = 0; i < 3 && grid[i][j] == ch; ++i);
		if (i == 3)
			return SUCC;
	}
	// diagonal 
	for (i = 0; i < 3 && grid[i][i] == ch; ++i);
	if (i == 3)
		return SUCC;
	for (j = 0; j < 3 && grid[2 - j][j] == ch; ++j);
	if (j == 3)
		return SUCC;

	return FAIL;
}
