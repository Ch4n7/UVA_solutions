// uva 442
// submission number: 21472408
// ACCEPTED
#include <iostream>
#include <stack>
#include <map>
#include <string>
#include <cctype>	// characters handling

using namespace std;

struct _matrix{
	int	m, n;
	_matrix(int m = 0, int n = 0):m(m), n(n) {}
};

map<char, _matrix> mtrx;
stack<_matrix> stk;

int
main()
{
	int	N, i, m , n, cnt;
	char	ch;
	string	line;
	_matrix ma, mb, mc;

	cin >> N;
	for (i = 0; i < N; ++i) {
		cin >> ch >> m >> n;
		mtrx[ch] = _matrix(m, n);
	}
	// According to the consecutive input line, there is no need to use
	while (cin >> line) {	// cin.getline(cin, string).
		stk = stack<_matrix> ();
		cnt = 0;
		for (i = 0; i < line.length(); ++i) {	
			ch = line[i];
			if (isalpha(ch)) {
				ma = mtrx[ch];
				stk.push(ma);
			} else if (ch == ')') {
				mb = stk.top();
				stk.pop();
				ma = stk.top();
				stk.pop();
				if (ma.n != mb.m) {
					cnt = -1;	// means error
					break;
				} else {
					cnt += ma.m * ma.n * mb.n;	
					ma.n = mb.n;
					stk.push(ma);
				}
			}
		}
		// In the very end, there might be some matrix left in the stack
		while (!stk.empty()) {	// deal with the matrix left in the stack
			if (stk.size() == 1) {
				stk.pop();
			} else {
				mb = stk.top();
				stk.pop();
				ma = stk.top();
				stk.pop();
				if (ma.n != mb.m) {
					cnt = -1;	// means error
					break;
				} else {
					cnt += ma.m * ma.n * mb.n;	
					ma.n = mb.n;
					stk.push(ma);
				}
			}
		}
		if (cnt < 0)
			cout << "error" << endl;
		else
			cout << cnt << endl;
	}

	return 0;
}
