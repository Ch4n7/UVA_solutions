// copyright @ 2018, ch4n7
// uva 122, trees on the level
// keywords: bfs, node ADT, level traverse, tag on node
// ACCEPTED on 20180620

#include <iostream>
#include <string>
#include <new>
#include <queue>

using namespace std;

struct node {
	int value;
	int at;	// asigned times, only 1 is legal
	node *left, *right;
	node():value(-1), at(0), left(NULL), right(NULL) {}
};
node *root; 
queue<node*> q;
bool read_a_tree();
bool check(node*);
int print(node*);
int add_node(int, string);

int
main()
{
	while (read_a_tree()) {		// !!NOTE the structure of main() & read_a_tree()
		if (check(root))	
			print(root);
		else
			cout << "not complete";
		cout << endl;
		free(root);
	}

	return 0;
}

bool
read_a_tree()
{
	string  unit;
	int  start, end, val;

	root = new node;
	while (cin >> unit) {
		if (unit == "()")
			return true;	// read a tree, done
		start = unit.find('(') + 1;
		end = unit.find(',');
		val = stoi(unit.substr(start, end -start));	// stoi() was introduced in C++11
		start = end + 1;
		end = unit.find(')');
		add_node(val , unit.substr(start, end - start));
	}
	
	// if (cin.eof())  <-- here is no need, sin we have 'while (cin >> unit)'
	return false;	// reach the end of file
}

int
add_node(int value, string order)
{
	int  i;
	node*  r;

	r = root;
	for (i = 0; i < order.length(); ++i) {
		if (order[i] == 'L' ) {
			if (r -> left == NULL)
				r -> left = new node;
			r = r -> left;
		} 
		else if (order[i] == 'R') {
			if (r -> right == NULL)
				r -> right = new node;
			r = r -> right;
		}
	}
	r -> value = value;
	(r -> at)++;

	return 0;
}

bool
check(node *r)
{
	if (r == NULL)
		return true;
	if (r -> at != 1)	// assigned times is not 1, FAIL!
		return false;
	if (!check(r -> left) || !check(r -> right))
		return false;

	return true;
}

int
print(node *r)
{
	node *n;
	int cnt;

	cnt = 0;
	q.push(r);
	while (!q.empty()) {
		n = q.front();
		q.pop();
		if (cnt++) cout << ' ';
		cout << n -> value;
		if (n -> left != NULL)
			q.push(n -> left);
		if (n -> right != NULL)
			q.push(n -> right);
	}

	return 0;
}

int
free(node *r)
{
	if (r == NULL)
		return 0;
	free(r -> left);
	free(r -> right);
	delete r;

	return 0;
}
