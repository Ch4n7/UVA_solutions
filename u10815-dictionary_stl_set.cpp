#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <set>

using namespace std;

int
main()
{
	int	i;
	string text, word;
	stringstream ss;
	set<string> dict;
	set<string>::iterator it;

	while (cin >> text) {
		/* can't handle cases like, "I'm the one. He'd like to go."
		 *                            ^             ^
		 *
		for (it = text.begin(); it != text.end();) {
			ch = *it;
			if (isalpha(ch)) {// if is alphabet, keep the lower case
				*it  = tolower(ch); 
				++it;
			}
			else	// if not alphabet, delete!
				text.erase(it);	// NOTE: no ++it after delete one character
		}
		dict.insert(text);	
		*/

		for (i = 0; i < text.size(); ++i) {
			if (isalpha(text[i]))
				text[i] = tolower(text[i]);
			else 
				text[i] = ' ';			
		}
		stringstream ss(text);	// NOTE! trick
		while (ss >> word)
			dict.insert(word);
	}

	for (it = dict.begin(); it != dict.end(); ++it)
		cout << *it << endl;

	return 0;
}
