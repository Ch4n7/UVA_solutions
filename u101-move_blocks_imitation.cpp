// UVa 101 - The Blocks Problem, move the blocks
// Key: C++ STL, vector
#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int maxn = 25;
int n;
vector<int> pile[maxn];

// Define common operation:

// find which pile 'p' the block 'b' is in and its height 'h'
int
find_block(int b, int &p, int &h)
{
	int	i, j;

	for (i = 0; i < n; ++i)
		for (j = 0; j < pile[i].size(); ++j)
			if (pile[i][j] == b) {
				p = i;
				h = j;
				return 0;
			}

	return -1;
}

// move the top one of pile 'ps' to pile 'pt'
int
move_top_block(int ps, int pt)
{
	int	b;

	b = pile[ps].back();
	pile[ps].pop_back();
	pile[pt].push_back(b);

	return 0;
}

// return all the blocks where in the pile 'p' to their initial pile from height 'h' up to the top
int
return_blocks(int p, int h)
{
	while (pile[p].size() > h + 1)
		move_top_block(p, pile[p].back());

	return 0;
}

// move the top blocks of pile 'ps' to pile 'pt'
int
pile_over(int ps, int h, int pt)
{
	int	i;

	for (i = h; i < pile[ps].size(); ++i)
		pile[pt].push_back(pile[ps][i]);
	pile[ps].resize(h);

	return 0;
}

int
print_piles()
{
	int	i, j;

	for (i = 0; i < n; ++i) {
		cout << i << ':';
		for (j = 0; j < pile[i].size(); ++j)
			cout << ' ' << pile[i][j];
		cout << endl;
	}

	return 0;
}

int
initial_pile()
{
	int	i;

	for (i = 0; i < n; ++i)
		pile[i].push_back(i);

	return 0;
}

int
main()
{
	int	s, ps, hs, t, pt, ht;
	string	op1, op2;

	cin >> n;
	
	initial_pile();
	while (cin >> op1 >> s >> op2 >> t) {
		find_block(s, ps, hs);
		find_block(t, pt, ht);
		// !!same pile, ignore, or dead-loop in pile_over()
		if (ps == pt)
			continue;
		if (op1 == "move")
			return_blocks(ps, hs);
		if (op2 == "onto")
			return_blocks(pt, ht);
		pile_over(ps, hs, pt);
	}

	print_piles();

	return 0;
}
