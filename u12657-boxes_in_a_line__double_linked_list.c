// uva 12657
// Keyword: double linked list with array implementation
// ACCEPTED

#include <stdio.h>
#define MAX 100000

int left[MAX + 2], right[MAX + 2];	// extra 2 items: head and tail
int link(int, int);

/* This is the first verson that can also be accpeted, but not so clear.
int
main()
{
	int	c, n, m, i, head, tail, inv,
		op, x, y, tmp, odd;
	long long sum;

	c = 1;
	while (scanf("%d%d", &n, &m) == 2) {
		inv = 0;
		head = 0;
		tail = n + 1;
		// initialization for head node and left node
		right[head] = 1;
		left[tail] = n;
		// initial order, fill the box i's left and right
		for (i = 1; i <= n;  ++i) { 
			left[i] = i - 1;
			right[i] = i + 1;
		}
		for (i = 0; i < m; ++i) {
			scanf("%d", &op);
			// when the sequence is inverse now, 
			// find the op that has the same effect, 
			// keep the same relative order of these boxes 
			if (inv) {
				if (op == 1)
					op = 2;
				else if (op == 2)
					op = 1;
			}
				// when op is swap, no need to change
			switch (op) {
				case 1:
					scanf("%d%d", &x, &y);
					if (right[x] != y) {
						// first, link the two sides of x
						right[left[x]] = right[x];
						left[right[x]] = left[x];
						// and move the x to the left to y
						right[left[y]] = x;	// gap #1
						left[x] = left[y];
						right[x] = y;		// gap #2
						left[y] = x;
					}
					break;
				case 2:
					scanf("%d%d", &x, &y);
					if (left[x] != y) {
						// first, link the two sides of x
						right[left[x]] = right[x];
						left[right[x]] = left[x];
						// and, move the x to the right of y
						right[x] = right[y];	// gap #2
						left[right[y]] = x;
						right[y] = x;		// gap #1
						left[x] = y;
					}
					break;
				case 3:	// swap, swap the sides' info of x and y
					scanf("%d%d", &x, &y);
					if (right[x] == y) {	// if x is just left to y
						right[left[x]] = y;
						left[y] = left[x];
						right[x] = right[y];
						left[right[y]] = x;
						right[y] = x;
						left[x] = y;
					} else if (left[x] == y) { // x just right to y
						right[left[y]] = x;
						left[x] = left[y];
						right[y] = right[x];
						left[right[x]] = y;
						right[x] = y;
						left[y] = x;
					} else { 	
						// first, swap the position of x and y
						tmp = left[x];
						left[x] = left[y];
						left[y] = tmp;
						tmp = right[x];
						right[x] = right[y];
						right[y] = tmp;
						// link the swapped 'x' and its both sides
						right[left[x]] = x;
						left[right[x]] = x;
						// link the swapped 'y' and its both sides
						right[left[y]] = y;
						left[right[y]] = y;
					}
					break;
				case 4:
					inv = !inv;	// false: in sequence
					break;		// true: inverse
			}
		}
		sum = 0;
		odd = 1;
		if (!inv) {
			for (i = right[head]; i != tail; i = right[i]) {
				if (odd)
					sum += i; 
				odd = !odd;
			}
		} else {	// if inverse now, from the tail to the head
			for (i = left[tail]; i != head; i = left[i]) {
				if (odd)
					sum += i;
				odd = !odd;
			}
		}
		printf("Case %d: %lld\n", c++, sum);
	}

	return 0;
}
*/

// clear version
int
main()
{
	long long  sum;
	int  c, n, m, i, op, x, y, head, tail,
	     lx, xr, ly, yr, odd, inv;

	c = 1;
	while (scanf("%d%d", &n, &m) == 2) {
		head = 0;
		tail = n + 1;
		inv = 0;
		for (i = 0; i <= n; ++i)
			link(i, i + 1);
		for (i = 0; i < m; ++i) {
			scanf("%d", &op);
			if (op == 4) {
				inv = !inv;
				continue;
			}
			scanf("%d%d", &x, &y);
			lx = left[x];
			xr = right[x];
			ly = left[y];
			yr = right[y];
			if (op == 3) {
				if (xr == y) {
					link(lx, y);
					link(y, x);
					link(x, yr);
				} else if (y == lx) {
					link(ly, x);
					link(x, y);
					link(y, xr);
				} else {
					link(lx, y);
					link(y, xr);
					link(ly, x);
					link(x, yr);
				}
				continue;
			}
			if (inv)
				op = 3 - op;	// 2 <-> 1
			if (op == 1 && xr != y) {
				link(lx, xr);
				link(ly, x);
				link(x, y);
			} else if (op == 2 && lx != y) {
				link(lx, xr);
				link(y, x);
				link(x, yr);
			}
		}
		sum = 0;
		odd = 1;
		if (!inv) {
			for (i = right[head]; i != tail; i = right[i]) {
				if (odd)
					sum += i; 
				odd = !odd;
			}
		} else {	// if inverse now, from the tail to the head
			for (i = left[tail]; i != head; i = left[i]) {
				if (odd)
					sum += i;
				odd = !odd;
			}
		}
		printf("Case %d: %lld\n", c++, sum);
	}

	return 0;
}

int
link(int l, int r) {
	right[l] = r;
	left[r] = l;

	return 0;
}
