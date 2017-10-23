#include <iostream>
#include <string>
#include <algorithm>
#define MAXN 22

using namespace std;

unsigned long long factorials[MAXN];
unsigned long long factorial(int);	// 20! will exceed the usual integer type

int
main()
{
	int	k, i, l, p;
	unsigned long long	n, f;
	string	s;

	cin >> k;
	while (k--) {
		cin >> s >> n;
		sort(s.begin(), s.end());	// sort first
		l = s.size();
		for (i = l - 1; i >= 0; --i) {
			f = factorial(i);	// The strings in the permutation are grouped
			p = n / f;		// in the number of factorial(l) with the same 
			n = n % f;		// character started with, where the 'l' is the
			cout << s.at(p);	// current length of the string s.
			s.erase(p, 1);		// Also in each group of the strings, it can be 
						// grouped likely recursively.
		}	
		cout << endl;
	}

	return 0;
}

unsigned long long
factorial(int n)
{
	if (n == 0)	// 0! equals to 1
		return 1;
	// if there is no record in factorials[], then compute recursively
	if (factorials[n] == 0)
		factorials[n] = n * factorial(n - 1);

	return factorials[n];
}
