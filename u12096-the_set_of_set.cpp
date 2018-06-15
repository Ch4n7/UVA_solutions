// uva 12096 - The SetStack Computer
// the example of AOPAPCC II, on page 190
// Keyword: set of set, C++ STL set, map, vector

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <iterator>
#include <algorithm>

using namespace std;

typedef set<int>  _set;
map<_set, int> id_cache;	// NOTE! this method
vector<_set> set_cache;

int id(const _set&);

int
main()
{
	int	nca, nop;
	string	op;
	stack<int>	ss;
	_set	s1, s2, s0;


	cin >> nca;
	while (nca--) {
		cin >> nop;
		while (nop--) {
			cin >> op;
			if ("PUSH" == op) {
				ss.push(id(_set()));
			}
			else if ("DUP" == op) {
					ss.push(ss.top());
			} else {
				s1 = set_cache[ss.top()];
				ss.pop();
				s2 = set_cache[ss.top()];
				ss.pop();
				s0.clear();
				if ("UNION" == op) {
					set_union(s1.begin(), s1.end(),
							s2.begin(), s2.end(), 
							inserter(s0, s0.begin()));
				}
				else if ("INTERSECT" == op) {
					set_intersection(s1.begin(), s1.end(),
							s2.begin(), s2.end(),
							inserter(s0, s0.begin()));
				}
				else if ("ADD" == op) {
					s0 = s2;
					s0.insert(id(s1));
				}
				ss.push(id(s0));
			}
			cout << set_cache[ss.top()].size() << endl;
		}
		cout << "***" << endl;
	}

	return 0;
}

int 
id(const _set &x) {
	if (id_cache.count(x))
		return id_cache[x];
	// If not exists, create it in set_cache
	set_cache.push_back(x);
	return id_cache[x] = set_cache.size() - 1;
}
