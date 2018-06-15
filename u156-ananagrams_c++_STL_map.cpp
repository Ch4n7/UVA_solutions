// uva 156, 20180512, ch4n7
// Keywords, C++ STL map
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cctype>
#include <algorithm>

using namespace std;

string after(const string &);

int
main()
{
	int	i;
	string word, basic_word;
	vector<string> text, ans;
	map<string, int> cnt;

	while (cin >> word && word != "#") {
		text.push_back(word);
		basic_word = after(word);
		if (cnt.count(basic_word))
			cnt[basic_word]++;
		else
			cnt[basic_word] = 1;
	}

	for (i = 0; i < text.size(); ++i)
		if (cnt[after(text[i])] == 1)
			ans.push_back(text[i]);
	sort(ans.begin(), ans.end());
	for (i = 0; i < ans.size(); ++i)
		cout << ans[i] << endl;

	return 0;
}

string
after(const string & word)
{
	int	i;
	string	after;

	after = word;
	for (i = 0; i < word.size(); ++i)
		after[i] = tolower(word[i]);
	sort(after.begin(), after.end());
	
	return after;
}

