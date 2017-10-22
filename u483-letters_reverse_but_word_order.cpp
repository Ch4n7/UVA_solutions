#include <iostream>
#include <stack>

using namespace std;

int
main()
{
	char	ch;
	stack<char>	s;

	while (cin.get(ch)) {	// not cin >> ch, can't readin whitespace etc
		switch (ch) {
			case ' ':
			case '\n':
				while (!s.empty()) {
					cout << s.top();
					s.pop();
				}
				cout << ch;
				break;
			default:
				s.push(ch);
		}
	}

	return 0;
}
