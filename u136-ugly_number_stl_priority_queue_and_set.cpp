#include <iostream>
#include <vector>
#include <set>
#include <queue> // priority queue

using namespace std;

typedef long long LL;
const int Nth = 1500;
const int NF = 3;
const int factor[NF] = {2, 3, 5};

int
main()
{
	LL t, k;
	int i, j;
	set<LL> already;	// already produced ugly numbers' set
	priority_queue<LL, vector<LL>, greater<LL> >	pq;
					//        ^ there must be a space
	pq.push(1);
	already.insert(1);
	for (i = 1; i < Nth; ++i) {
		t = pq.top();
		pq.pop();
		for (j = 0; j < NF; ++j) {
			k = t * factor[j];	// here, will lead to overflow of 'int'
			if (!already.count(k)) { // so, we are using 'long long'
				pq.push(k);
				already.insert(k);
			}
		}
	}		
	cout << "The " << Nth << "'th ugly number is " << pq.top() << ".\n"; 

	return 0;
}
