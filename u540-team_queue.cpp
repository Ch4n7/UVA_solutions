#include <iostream>
#include <map>
#include <queue>
#include <string>

using namespace std;

const int MAX_TEAMS = 1024;

int
main()
{
	int	no_k, nt, np, x, i, j, tid;
	string	op;

	no_k = 1;
	do {
		cin >> nt;
		if (0 == nt) break;
		cout << "Scenario #" << no_k++ << endl;

		map<int, int> team_id;
		queue<int> team_queue, subqueue[MAX_TEAMS];

		for (i = 0; i < nt; ++i) {
			cin >> np;
			for (j = 0; j < np; ++j) {
				cin >> x;
				team_id[x] = i;
			}
		}

		do {
			cin >> op;
			if ("STOP" == op)
				break;
			else if ("ENQUEUE" == op) {
				cin >> x;
				tid = team_id[x];
				if (subqueue[tid].empty())	// no teamates in queue yet
					team_queue.push(tid);
				subqueue[tid].push(x);
				/*if (!subqueue[tid].empty()) { // has teamates in queue
					subqueue[tid].push(x);	
				}
				else {	// no teamates in queue
					team_queue.push(tid);
					subqueue[tid].push(x);
				}*/
			}
			else if ("DEQUEUE" == op) {
				tid = team_queue.front();
				cout << subqueue[tid].front() << endl;
				subqueue[tid].pop();
				if (subqueue[tid].empty())
					team_queue.pop();
			}
		} while (true);
		
		cout << endl;
	} while (true);

	return 0;
}
