#include <iostream>
#include <map>

using namespace std;

map<int, int> piles;
int build(int);
int print_piles();

int
main()
{
	int	c;

	c = 1;
	while (build(0) > 0) {	// build root
		cout << "Case " << c++ << ":" << endl;
		print_piles();
		cout << endl;
		piles.clear();
	}

	return 0;
}

int
init()
{
	piles.clear();
}

int
build(int pos)
{
	int	nl;	// number in this node (root, recursively)

	cin >> nl;
	if (nl != -1) {
		/*
		if (piles.count(pos) > 0)
			piles[pos] += nl;
		else
			piles[pos] = nl;
			*/
		piles[pos] += nl;
		build(pos - 1); // left child
		build(pos + 1);	// right child
	}

	return nl;	// return the number in the root 
}

int
print_piles()
{
	int	i;
	map<int, int>::iterator it;

	for (it = piles.begin(), i = 0; it != piles.end(); ++it, ++i) {
		if (i) cout << ' ';	// keep formatted
		cout << it -> second;
	}
	cout << endl;

	return 0;
}
