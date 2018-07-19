// Copyright @ 2018, ch4n7
// uva 1103 - Ancient Messages
// Keywords: the appliance of floodfill algorithm

#include <stdio.h>
#include <string.h>
#define MAX_H 200
#define MAX_W 50
#define DEL -1	// deleted
#define WHITE 0
#define BLACK 1

int image[MAX_H + 2][MAX_W * 4 + 2], H, W;
int bin[16][4];
char symbol[6] = {'A', 'D', 'J', 'K', 'S', 'W'};
int amount[6];					// A D J K S W	- alphabetic order
int hole2symbol[6] = {5, 0, 3, 2, 4, 1};	// W A K J S D  - holes from 0 to 5
int cnt;
int set_bin();
int read_image();
int add_margin();
int outside(int, int);
int whitefill(int, int, int);
int find_hole(int, int);

int
main()
{
	int	c, i, j;

	set_bin();
	c = 1;
	while (scanf("%d%d", &H, &W) == 2
			&& H != 0 && W != 0) {
		read_image();
		// Add white surroungdings, start from image[0][0], fill the background
		// to seperate symbols.
		add_margin(); 
		whitefill(0, 0, DEL);	
		// count symbol
		memset(amount, 0 ,sizeof(amount));
		for (i = 1; i <= H; ++i)
			for (j = 1; j <= W * 4; ++j) {
				if (image[i][j] == 1) {	// find a new symbol 
					cnt = 0;
					find_hole(i, j);
					amount[hole2symbol[cnt]]++;	
				}
			}
		// print out 
		printf("Case %d: ", c++);
		for (i = 0; i < 6; ++i)
			while (amount[i]--)
				printf("%c", symbol[i]);
		printf("\n");

	}

	return 0;
}

// Initial the 'bin' array, where the binaries of 0 ~ 15 stores.
// preparation for reading image, run only once in advance
int
set_bin()
{
	int	i, j, n;

	memset(bin, 0, sizeof(bin));
	for (i = 0; i < 16; ++i) {
		j = 3;	// big endian
		n = i;
		while (n != 0) {	// decimal to binary
			bin[i][j--] = n % 2;
			n /= 2;
		}
	}

	return 0;
}

// read a image
// from string to 'int' two-dimentional array 
int
read_image()
{
	char	ch;
	int	i, j, k;

	for (i = 1; i <= H; ++i) {
		getchar();	// discard the line feed left in last line
		for (j = 0; j < W; ++j) {
			scanf("%c", &ch);
			if (ch >= '0' && ch <= '9')
				for (k = 0; k < 4; ++k)
					image[i][(j * 4 + 1) + k] = bin[ch - '0'][k];
			else if (ch >= 'a' && ch <= 'f')
				for (k = 0; k < 4; ++k)
					image[i][(j * 4 + 1) + k] = bin[ch - 'a' + 10][k];
		}
	}

	return 0;
}

// add surrounding to the image
int
add_margin()
{
	int	i, j, 
		rows[2] = {0, H + 1},
		cols[2] = {0, W * 4 + 1};	// save some code lines

	for (i = 0; i < 2; ++i)
		for (j = 0; j <= cols[1]; ++j)	// top and bottom
			image[rows[i]][j] = 0;
	for (i = 0; i <= rows[1]; ++i)
		for (j = 0; j < 2; ++j)		// left and right
			image[i][cols[j]] = 0;

	return 0;
}

// check whether the position [i, j] is out of the image 
int
outside(int i, int j)
{
	return i < 0 || i > (H + 1) || j < 0 || j > (W * 4 + 1);
}

// change the white pixels into the 'color'
int
whitefill(int i, int j, int color)	// flood fill the white connected region
{
	if (outside(i, j) || image[i][j] != WHITE)
		return 0;

	image[i][j] = color;
	whitefill(i - 1, j, color);	// floodfill-like
	whitefill(i + 1, j, color);
	whitefill(i, j - 1, color);
	whitefill(i, j + 1, color);

	return 0;
}

int
find_hole(int i, int j)
{
	if (outside(i, j) || image[i][j] == DEL)
		return 0;

	if (image[i][j] == BLACK) {
		image[i][j] = DEL;	
		find_hole(i - 1, j);	// another floodfill-like to change black into deleted
		find_hole(i + 1, j);
		find_hole(i, j - 1);
		find_hole(i, j + 1);
	} else if (image[i][j] == WHITE) {	// find a hole
		cnt++;
		whitefill(i, j, DEL);	// once find a hole, flood fill it with -1
	}

	return 0;
}
