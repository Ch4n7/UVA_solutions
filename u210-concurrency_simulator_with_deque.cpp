#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <queue>
#include <deque>
#include <map>

#define STAT_TYPE 5
#define MAX_PROG 11 
#define MAX_STAT 26 

using namespace std;

int blk_global, blk[MAX_PROG];	// 0 - not blocked; 1 - blocked.
int times[STAT_TYPE];
int curs[MAX_PROG];	// current position in each program
string program[MAX_PROG][MAX_STAT];
deque<int> ready;
queue<int> blocked;
map<char, int> variables;

int run(int, int);

int
main()
{
	int	C, n, quant, i, j, p;
	string	stat;

	cin >> C;
	while (C--) {
		cin >> n;
		for (i = 0; i < STAT_TYPE; ++i)
			cin >> times[i];
		cin >> quant;
		cin.get();
		// read the programs and seperatedly stored
		for (i = 0; i < n; ++i) {
			j = 0;
			do {
				getline(cin, stat);
				program[i][j] = stat;
				++j;
			} while (stat != "end");
			curs[i] = 0;	
		} 
		// get the enviroment ready
		ready.clear(); 
		for (i = 0; i < n; ++i)	// the initial order
			ready.push_back(i);	
		blocked = queue<int>();	// the way to clear queue
		variables.clear();
		blk_global = 0;
		memset(blk, 0, sizeof(blk));

		while (!ready.empty()) {
			p = ready.front();
			ready.pop_front();
			// If current statement is "end", run() return value 1.
			if (!run(p, quant) && !blk[p])	
				ready.push_back(p);
		}
		if (C)	cout << endl;
	}	

	return 0;
}

int
run(int prog, int quant)
{
	char	var;
	int	type, value, p;
	string  stat;

	while (quant > 0) {
		stat = program[prog][curs[prog]];

		if (stat.find("=") != string::npos)
			type = 0;
		else if (stat.find("print") != string::npos)
			type = 1;
		else if (stat == "lock")
			type = 2;
		else if (stat == "unlock")
			type = 3;
		else if (stat == "end")
			type = 4;
		else
			type = -1;
		switch (type) {
			case 0:
				sscanf(stat.c_str(), "%c = %d", &var, &value);
				variables[var] = value;
				quant -= times[type];
				curs[prog]++;
				break;
			case 1:
				sscanf(stat.c_str(), "print %c", &var);
				cout << (prog + 1) << ": " << variables[var] << endl;
				quant -= times[type];
				curs[prog]++;
				break;
			case 2:
				if (!blk_global) {
					blk_global = 1;
					quant -= times[type];
					curs[prog]++;
				} 
				else {	// blocked already
					quant = -1;	// lose their remaining quantaum	
					blocked.push(prog);
					blk[prog] = 1;
				}
				break;
			case 3:
				blk_global = 0;
				if (!blocked.empty()) {
					p = blocked.front();
					blocked.pop();
					blk[p] = 0;
					ready.push_front(p);
				}
				quant -= times[type];
				curs[prog]++;
				break;
			case 4:
				curs[prog]++;
				return 1;
		}
	}
	
	return 0;
}
