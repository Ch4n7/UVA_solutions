// Copyright @ 2018, ch4n7
// uva 548 - tree
// Keywords: build binary tree with postorder list and inorder list
// WRONG ANSWER but accepted by debug data: might be something wrong
// with my read_order() using strchr()
// *NOTE: There is another version that be accepted, just modified in read_order()
// where I take the std::stringstream.

#include <stdio.h>
#include <string.h>

#define MAXN (10000+10)
#define MAXM (10000*10000)

int inorder[MAXN], postorder[MAXN], nn;	// node number
int left[MAXN], right[MAXN];
int optimal, optleaf;
int read_order();
int build(int, int, int, int);
int dfs(int, int);

int
main()
{
	int	root;

	while ((nn = read_order()) > 0) {
		root = build(0, nn - 1, 0, nn - 1);
		optimal = MAXM;
		optleaf = -1;
		dfs(root, 0);
		printf("%d\n", optleaf);
	}

	return 0;
}

int
read_order()
{
	int	i;
	char	line[4 * MAXN], *start;
	
	if (fgets(line, 4 * MAXN, stdin) == NULL)	// read in inorder
		return -1;
	i = 0;
	start = line;		// here, another way to readin with c++ class 'stringstream'
	while (sscanf(start, "%d", inorder + i) == 1)  {
		i++;
		while (*start == ' ') start++; // skip the consecutive whitespace
		if ((start = strchr(start, ' ')) == NULL) break;
	}
	nn = i;
	if (fgets(line, 4 * MAXN, stdin) == NULL)
		return -1;
	i = 0;
	start = line;
	while (sscanf(start, "%d", postorder + i) == 1) {
		i++;
		while (*start == ' ') start++;
		if ((start = strchr(start, ' ')) == NULL) break;
	}
	if (nn != i) // the number of nodes should be equal in inorder and postorder
		return -1;

	return nn;
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
