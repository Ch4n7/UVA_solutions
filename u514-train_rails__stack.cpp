#include <iostream>
#include <stack>
#include <queue>	// there is no need to keep 'a station' as a queue
			// but it will be clear if queue

using namespace std;

const int sentinel = 0;
int n, t, i, casen, succ;
stack<int> c;	// C station
queue<int> a;	// A station
int run();

int
main()
{
	casen = 0;
	while (cin >> n && n != 0) {
		if (casen++)
			cout << endl;
		while (run());
	}
	// cout << endl;	
	// Weird!! Added this one, it will be AC, otherwise Presentation Error! 

	return 0;
}

int
run()
{
	a = queue<int> ();	// initial order again
	for (i = 1; i <= n; ++i)
		a.push(i);
	c.push(sentinel); // put the sentinel to c station, make sure the process work 
	succ = 1;
	cin >> t;
	if (t == 0)
		return 0;	
	i = 1;
	while (i < n) {
		if (t == c.top()) {	// finally, always from C to B
			c.pop();
			cin >> t;	// readin a train again
			i++;
		} else if (t > c.top()) {	// in this case, 
			c.push(a.front());	// drive a train to the stack from A to C
			a.pop();
		} else {
			succ = 0;	// if need a train less than c.top()
			break;		// then it can be successful
		}
	} 
	for (; i < n; ++i) cin >> t;	// discard the remains
	if (succ)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}
