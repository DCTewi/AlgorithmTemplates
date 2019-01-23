/*
 * SPFA 也适用于负权图
 * SPFA的时间复杂度O(N*M)=O(V*E)要大于堆优化的O((N + M) * logN)
 * 所以在正权图中最好使用堆优化Dij(1e5已经跑不动了)
 */

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 5;
const int MAXM = 5e5 + 5;

struct Edge
{
	Edge(){}
	Edge(int t, int c)
	{
		this->to = t; this->cost = c;
	}

	int to, cost;
}temp;
queue<int> q;
vector<Edge> edge[MAXN];
int dis[MAXN], vis[MAXN];

void spfa(int s)
{
	memset(dis, 0x3f, sizeof(dis));

	vis[s] = 1; dis[s] = 0;
	q.push(s);

	while (!q.empty())
	{
		int u = q.front();
		for (int i = 0; i < edge[u].size(); i++)
		{
			int v = edge[u][i].to;
			int cost = edge[u][i].cost;
			if (dis[v] > dis[u] + cost)
			{
				dis[v] = dis[u] + cost;

				if (!vis[v])
				{
					vis[v] = 1;
					q.push(v);
				}
			}
		}
		q.pop();
		vis[u] = 0;
	}
}

int n, m, s;

int main()
{
	scanf("%d%d%d", &n, &m, &s);
	for (int i = 0; i < m; i++)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		edge[u].push_back(Edge(v, w));
		//edge[v].push_back(Edge(u, w)); //<-无向图
	}

	spfa(s);

	for (int i = 1; i <= n; i++)
	{
		printf("%d ", (dis[i] != 0x3f3f3f3f? dis[i]: 0x7fffFFFF));
	}
	printf("\n");

	return 0;
}

