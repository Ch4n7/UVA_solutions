// UVa 10305 ordering tasks
// Keywords: topsort, indegree zero first
// 20180720 ACCEPTED

#include <stdio.h>
#include <string.h>	// memset()
#define MAXN 128

int in[MAXN], adj[MAXN][MAXN];	// indegree, adjacent matrix
int n, m;

int
main()
{
	int	i, u, v, cnt;

	while (scanf("%d%d", &n, &m) == 2) {
		if (n == 0 && m == 0) 
			break;

		memset(adj, 0, sizeof(adj));
		memset(in, 0, sizeof(in));
		for (i = 0; i < m; ++i) {
			scanf("%d%d", &u, &v);
			if (!adj[u][v]) {	// ingnore the existed edge
				adj[u][v] = 1;
				in[v]++;
			}
		}
		cnt = 0;
		while(cnt < n) {	// until output n of tasks
			for (u = 1; u <= n; ++u) {
				if (in[u] == 0) {
					printf("%d", u);
					in[u] = -1;
					cnt++;
					for (v = 1; v <= n; ++v)
						if (adj[u][v])
							in[v]--;
					if (cnt == n)
						printf("\n");
					else
						printf(" ");
				}
			}
		}
	}

	return 0;
}

