// Copyright @ 2018, ch4n7
// UVa 816 - Abbott's Revenge
// Keywords: bfs, bfs-like, maze problem
// 20180719 ACCEPTED
#include <iostream>
#include <string>	// string class
#include <cstring>	// memset(), strchr()
#include <queue>
#include <vector>

using namespace std;

// the state on position ('row', 'col') and facing the direction of 'face'
struct state {
	int	row, col;
	int	face;
	state(int r = 0, int c = 0, int f = -1) :row(r), col(c), face(f) {}
	//state(int r = 0, int c = 0; int f = -1) {row = r; col = c; face = f;}
};

const int MAX = 9 + 1, DIRS = 4, TURNS = 3;// rows, columns, directions, turns
const char *directions = "NESW", *turns = "FLR"; 
int dir_id(char); // 0 facing north, 1 east, 2 south, 3 west; clockwise 
int turn_id(char); // 0 forwad, 1 left, 2 right
// increment of row and column to north, east, south, and west 
const int dr[DIRS] = {-1, 0, 1, 0}, dc[DIRS] = {0, 1, 0, -1}; 
int can_pass[MAX][MAX][DIRS][TURNS];	
string maze_name;
struct state start0, start, goal;
int dist[MAX][MAX][DIRS];
state previous[MAX][MAX][DIRS];
int read_case();
int solve();
state walk(state st, int turn);	// from state u to state v according to 'turn'
int inside(state);	// check if inside the legal range
int print_route();

int
main()
{
	while (read_case()) {
		cout << maze_name << endl;
		if (solve())
			print_route();
		else
			cout << "  No Solution Possible" << endl;
	}

	return 0;
}

inline int dir_id(char c) { return strchr(directions, c) - directions; }
inline int turn_id(char c) { return strchr(turns, c) - turns;}

// deal with readin
int
read_case()
{
	int	r, c, f, t, i;
	string	s;

	cin >> maze_name;
	if (maze_name == "END")
		return 0;

	memset(can_pass, 0, sizeof(can_pass));
	cin >> r >> c >> s;	// start state
	f = dir_id(s[0]);
	start0 = state(r, c);	// the original start
	start = state(r + dr[f], c + dc[f], f);	// new struct, the real start point
	cin >> r >> c;		// goal position
	goal = state(r, c, -1);
	while (cin >> r && r != 0) {
		cin >> c;
		while (cin >> s && s != "*") {
			f = dir_id(s[0]);
			for (i = 1; i < s.length(); ++i) {
				t = turn_id(s[i]);
				can_pass[r][c][f][t] = 1;
			}
		}
	}

	return 1;
}

// bfs to search the route in the maze
int
solve()
{
	int	i;
	state	u, v;
	queue<state> Q;

	memset(dist, -1, sizeof(dist));	
	//Q = queue<state>(); // clear up queue 'Q'
	dist[start.row][start.col][start.face] = 0;
	Q.push(start);
	while (!Q.empty()) {
		u = Q.front();
		Q.pop();
		if (u.row == goal.row && u.col == goal.col) {
			goal.face= u.face;	// record where we reach the goal
			return 1;	// reach
		}
		for (i = 0; i < TURNS; ++i)
			if (can_pass[u.row][u.col][u.face][i]) {
				v = walk(u, i);
				if (inside(v) && dist[v.row][v.col][v.face] < 0) {
					dist[v.row][v.col][v.face]=dist[u.row][u.col][u.face]+1;
					previous[v.row][v.col][v.face] = u;
					Q.push(v);
				}
			}
	}

	return 0;	// no solution possible
}

state
walk(state st, int turn)
{
	int	face;

	face = st.face;
	if (turn == 1)	// left
		face = (face + 3) % DIRS;
	else if (turn == 2)	// right
		face = (face + 1) % DIRS;
	// else if (turn == 0) // forward, do nothing

	return state(st.row + dr[face], st.col + dc[face], face);
}

inline int inside(state st) { return st.row > 0 && st.row < MAX && st.col > 0 && st.col < MAX;}

int
print_route()
{
	int	cnt, i;
	state	u;
	vector<state> ans;

	/* there is a BUG
	u = goal;
	do {
		ans.push_back(u);
		u = previous[u.row][u.col][u.face];
	} while (dist[u.row][u.col][u.face] >= 0);	// BUG here! dist[0][0][-1] == 0
	*/
	u = goal;
	for (;;) {
		ans.push_back(u);
		if (dist[u.row][u.col][u.face] == 0) break;
		u = previous[u.row][u.col][u.face];
	}
	ans.push_back(start0);	// put in the original state at the end

	for (i = ans.size() - 1, cnt = 0; i >= 0; --i, ++cnt) {
		if (cnt % 10 == 0) 
			cout <<  "  ";
		else
			cout << ' ';
		cout << '(' << ans[i].row << ',' << ans[i].col << ')';
		if (cnt % 10 == 9 || i == 0)
			 cout << endl;
	}

	return 0;
}
