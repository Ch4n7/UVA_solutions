// uva 10474 
// Key: C++ STL, algoritm, sort(), lower_bound()
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 10000;

int
main()
{
	int	c, n, q, i, m,
		pos, marbles[MAXN];

	c = 1; // case#?
	while (cin >> n >> q) {
		if (n == 0 && q == 0) break;
		cout << "CASE# " << c++ << ':' << endl;
		for (i = 0; i < n; ++i)
			cin >> marbles[i]; 
		sort(marbles, marbles + n);	// sort() before lower_bound()
		for (i = 0; i < q; ++i) {
			cin >> m;
			pos = lower_bound(marbles, marbles + n, m) - marbles;	// lower_bound return the first position where the element is not less than 'm', NOTE: it may not be equal to 'm'
			if (pos < n && marbles[pos] == m)
				cout << m << " found at " << pos + 1 << endl;
			else
				cout << m << " not found" << endl;
		}
	}

	return 0;
}
