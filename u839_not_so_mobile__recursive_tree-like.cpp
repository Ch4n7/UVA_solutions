#include <iostream>

using namespace std;

int weight();

/*
int
main()
{
	int	i, c;	// cases

	cin >> c;
	for (i = 0; i < c; ++i) {
		if (i) cout << endl;	// no blank line before the first case
		if (weight() > 0)
			cout << "YES";
		else
			cout << "NO";
		cout << endl;
	}

	return 0;
}
*/

// a tidy main() process
int
main()
{
	int	c;

	cin >> c;
	while (c--) {
		cout << (weight() > 0 ? "YES" : "NO") << endl;
		if (c) cout << endl;	// no blank line after the last case
	}

	return 0;
}

int
weight()
{
	int	wl, dl, wr, dr;

	cin >> wl >> dl >> wr >> dr;
	if (wl == 0)
		wl = weight();
	if (wr == 0)
		wr = weight();
	if (wl < 0 || wr < 0 || wl * dl != wr * dr)
		return -1;	// weight less than 0 denotes not in quilibrium

	return wl + wr;
}
