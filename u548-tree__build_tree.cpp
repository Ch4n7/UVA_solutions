// Copyright @ 2018, ch4n7
// uva 548 - tree
// Keywords: build binary tree with postorder list and inorder list, 
//	std::stringstream to deal with 'string to int' repeatedly work
// ACCEPTED - 20180621

#include <iostream>
#include <sstream>

#define MAXN (10000+10)
#define MAXM (10000*10000)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stringstream;

int inorder[MAXN], postorder[MAXN];	
int left[MAXN], right[MAXN];
int optimal, optleaf;
int read_order();
int build(int, int, int, int);
int dfs(int, int);

int
main()
{
	int	root, nn;	// node number

	while ((nn = read_order()) > 0) {
		root = build(0, nn - 1, 0, nn - 1);
		optimal = MAXM;
		optleaf = -1;
		dfs(root, 0);
		cout << optleaf << endl;
	}

	return 0;
}

int
read_order()
{
	int	i, n;
	string	line;

	if (!getline(cin, line))
		return -1;
	stringstream ss1(line);
	i = 0;
	while (ss1 >> inorder[i]) i++;
	n = i;
	if (!getline(cin, line))
		return -1;
	stringstream ss2(line);
	i = 0;
	while (ss2 >> postorder[i]) i++;
	if (i != n)
		return -1;

	return n;
}
// return the root of subtree recursively, then build up whole tree from the root to leaves
int
build(int il, int ir, int pl, int pr)	// range of inorder[il..ir], postorder[pl..pr]
{
	int	root, i, nl, nr; // number of nodes in left and right subtree

	if (il > ir)
		return	-1; 
	root = postorder[pr];
	for (i = il; i <= ir; ++i)
		if (inorder[i] == root) break;
	nl = i - il;
	nr = ir - i;
	left[root] = build(il, il + nl - 1, pl, pl + nl - 1);	// recursively build
	right[root] = build(ir - nr + 1, ir, pr - nr, pr - 1);
	
	return root;
}

// return the sum of the nodes in path
int
dfs(int t, int sum)
{
	if (t < 0)
		return 0;	// nothing to do

	sum += t;
	if (left[t] < 0 && right[t] < 0) {
		if (sum < optimal || (sum == optimal && t < optleaf)) {
			optimal = sum;
			optleaf = t;
		}
	}
	dfs(left[t], sum);	// and searching go on.. to left child and righ child
	dfs(right[t], sum);

	return 0;
}
