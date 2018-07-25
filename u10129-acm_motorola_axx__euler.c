// Copyright @ 2018, ch4n7
// UVa 10129 play on words
// keywords: euler road, euler circle, dfs to check connected graph
// 20180725, ACCEPTED

#include <stdio.h>
#include <string.h>	// strlen()

#define MAXL 1010

int cnt;
int adj[26][26], in[26], out[26], odd[2];
int dfs(int);
int vis[26];

int
main()
{
	int	t, m, n, i, u, v, dio, doi, no, ret;
	char	word[MAXL];

	scanf("%d", &t);
	while (t--) {
		// readin
		scanf("%d", &m);
		memset(adj, 0, sizeof(adj));
		memset(in, 0, sizeof(in));
		memset(out, 0, sizeof(out));
		memset(vis, 0, sizeof(vis));
		n = 0;
		for (i = 0; i < m; ++i) {
			scanf("%s", word);
			u = word[0] - 'a';
			v = word[strlen(word) - 1] - 'a';
			// keep the graph
			if (!adj[u][v])
				adj[u][v] = 1;
			// count how many vertex that's referred to
			if (!vis[u]) {	
				n++;
				vis[u] = 1;
			}
			if (!vis[v]) {
				n++;
				vis[v] = 1;
			}
			// count the out-degree and in-degree of each vertix
			out[u]++;
			in[v]++;
		}
		// check the graph if connected
		cnt = 0;
		// search for the referred point
		for (u = 0; !vis[u]; ++u);	
		// dfs to count how many vertex that is connected to 'u'
		memset(vis, 0, sizeof(vis));	// for dfs() here
		dfs(u);	

		ret = 0;
		if (cnt == n) {	// connected
			no = 0;	// the number of odds
			for (u = 0; u < 26; ++u) {
				if (out[u] != in[u]) {
					if (no >= 2) break;	// more than 2 odd points
					odd[no++] = u;
				}
			}
			if (no == 2) {	// when it has 2 odd points
				dio = in[odd[0]] - out[odd[0]];
				doi = out[odd[1]] - in[odd[1]];
				if (dio == doi) {
					if (dio < 0)
						dio = -dio;
					if (dio == 1)
						ret = 1;
				}
			}
			if (no == 0) ret = 1;	// no odd points
		}
		if (ret)
			printf("Ordering is possible.\n");
		else
			printf("The door cannot be opened.\n");
	}

	return 0;
}

int
dfs(int u)
{
	int	v;

	if (vis[u])
		return 0;

	cnt++;
	vis[u] = 1;
	for (v = 0; v < 26; ++v)
		if (adj[u][v] || adj[v][u])	// graph with no direction
			dfs(v);

	return 0;
}
