// Copyright @ 2018, ch4n7
// uva 297 quadtrees
// keywoard: the recursive way to traversal of quadtrees
// ACCEPTED on 20180627

#include <iostream>
#include <string>

using namespace std;

string t1, t2;
int i1, i2;
int adding(int, int);
int pixel_count(string &, int &, int, int);
int pow(int, int);

int
main()
{
	int	amount, c;

	cin >> c;
	while (c--) {
		cin >> t1 >> t2;
		i1 = i2 = 0;
		amount = adding(0, 0);
		if (amount == 1)
			cout << "There is 1 black pixels." << endl;
		else
			cout << "There are " << amount << " black pixels." << endl;

	}

	return 0;
}

// adding() is to synchronize the positon of the tree in the addition process.
// The key of the function is when to move forward the index of 'tree'.
int
adding(int depth, int child)	// para 'child' is a marker, although it is not used at all
{
	int	amount;

	if (t1[i1] == 'f' || t2[i2] == 'f') {
		amount = pow(4, 5 - depth);
		if (t1[i1] == 'p')
			pixel_count(t1, i1, depth, 0);// for 'i1' increase
		else 
			i1++;
		if (t2[i2] == 'p')
			pixel_count(t2, i2, depth, 0);// for 'i2' increase
		else
			i2++;

	}
	else if (t1[i1] == 'e') {
		amount = pixel_count(t2, i2, depth, child);
		i1++;	// i2++ increased in pixel_count()
	}
	else if (t2[i2] == 'e') {
		amount = pixel_count(t1, i1, depth, child);
		i2++;
	}
	else if (t1[i1] == 'p' && t2[i2] == 'p') {
		i1++, i2++;
		amount = adding(depth + 1, 1)
			+ adding(depth + 1, 2)
			+ adding(depth + 1, 3)
			+ adding(depth + 1, 4);
	}

	return amount;
}

// The key of the function is when to move forward the 'pos' of 'tree'.
int	// para 'child' is a marker, although it is not used at all
pixel_count(string &tree, int &pos, int depth, int child)
{
	int	amount;

	if (tree[pos] == 'e') {
		amount = 0;
		pos++;	// move forward
	}
	else if (tree[pos] == 'f') {
		amount = pow(4, 5 - depth);
		pos++;	// move forward
	}
	else if (tree[pos] == 'p') {
		pos++;	// move forward, little different
		amount = pixel_count(tree, pos, depth + 1, 1)
			+ pixel_count(tree, pos, depth + 1, 2)	// four recursive call 
			+ pixel_count(tree, pos, depth + 1, 3)
			+ pixel_count(tree, pos, depth + 1, 4);
	}

	return amount;
}

int
pow(int base, int coef)
{
	int	i, mul;

	mul = 1;
	for (i = 0; i < coef; ++i)
		mul *= base;

	return mul;
}

