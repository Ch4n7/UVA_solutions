// 2018-06-14
// uva 11988, ACCEPTED
// keywords: C++ STL, linked list, insert from the begin and the end of the list

#include <iostream>
#include <string>
#include <list>

using namespace std;

int
main()
{
	int  i;
	string  input;
	list<char>  display;
	list<char>::iterator  cur;

	while (cin >> input) {
		display.clear();
		cur = display.begin();
		for (i = 0; i < input.length(); ++i) {
			if (input[i] == '[')
				cur = display.begin();
			else if (input[i] == ']')
				cur = display.end();
			else
				display.insert(cur, input[i]);
		}
		for (cur = display.begin(); cur != display.end(); ++cur)
			cout << *cur;
		cout << endl;
	}

	return 0;
}
