// Direct Access Table in C++ STL map
// uva 11340 - Newspaper, Accepted
// Copyright 2018, Ch4n7
#include <iostream>
#include <iomanip>	// std::setprecision, std::fixed in it
#include <map>

#define MAX_LINE 10000

using namespace std;

int
main()
{
	int	i, m, cases, price, amount;
	char	ch, line[MAX_LINE];
	map<char, int>	rules;	// C++ STL map is suitable for DAT
	
	cin >> cases;
	// setprecision(n)可控制输出流显示浮点数的数字个数;
	// setiosflags(ios::fixed)是用定点方式表示实数;
	// 如果setprecision(n)与setiosflags(ios::fixed)合用，
	// 可以控制小数点右边的数字个数。
	cout << fixed;	
	cout <<	setprecision(2);	
	while (cases--) {
		cin >> m;
		rules.clear();
		while (m--) {
			cin >> ch >> price;
			rules[ch] = price;
		}
		cin >> m;
		cin.get();	// discard the '\n' after m
		amount = 0;
		while (m--) {
			cin.getline(line, MAX_LINE);
			for (i = 0; line[i] != '\0'; ++i)
				amount += rules[line[i]];
		}
		cout << amount / 100.0 <<  "$" << endl;
	}

	return 0;
}
