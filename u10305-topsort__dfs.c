// Copyright @ 2018, ch4n7
// UVa 10305
// Keywords: dfs, topsort
// 20180724 ACCEPTED

#include <stdio.h>
#include <string.h> // memset()
#define MAXN 110

int vis[MAXN], adj[MAXN][MAXN], n, m, ans[MAXN], cnt;	// visited, adjacent matrix
int read();
int topsort();
int output();
int dfs(int);

int
main()
{
	while (read()) {
		if (topsort())
			output();
	}

	return 0;
}	

int
read()
{
	int	i, u, v;

	scanf("%d%d", &n, &m);
	if (n == 0 && m == 0)
		return 0;

	memset(adj, 0, sizeof(adj));
	for (i = 0; i < m; ++i) {
		scanf("%d%d", &u, &v);
		if (!adj[u][v])
			adj[u][v] = 1;
	}
	
	return 1;
}

int
topsort()
{
	int	i;

	memset(vis, 0, sizeof(vis));
	cnt = n;
	for (i = 1; i <= n; ++i)
		if (vis[i] == 0)
			if (!dfs(i))
				return 0;

	return 1;
}

int
dfs(int u)
{
	int	v;

	vis[u] = 1;	// 1 - currently visited
	for (v = 1; v <= n; ++v) {
		if (adj[u][v]) {
			if (vis[v] == 0) {
				if (!dfs(v))	// do the task v first
					return 0;
			}
			else if (vis[v] == 1)
				return 0;	// there is a circle
		}
	}
	vis[u] = 2;	// 2  - already output
	ans[cnt--] = u;	// now, there can be no task after task 'u', put it in the end

	return 1;
}

int
output()
{
	int	i;

	for (i = 1; i <= n; ++i) {
		printf("%d", ans[i]);
		if (i == n)
			printf("\n");
		else
			printf(" ");
	}
	
	return 0;
}
