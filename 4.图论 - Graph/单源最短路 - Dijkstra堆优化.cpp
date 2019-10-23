/*
 * Dijkstra适用于: 正权连通图
 */

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1E5 + 5;
const int MAXM = 5E5 + 5;

struct Node
{
	int dis, pos;

	Node(int d = 0, int p = 0) : dis(d), pos(p) {}

	bool operator>(const Node &other) const
	{
		return dis > other.dis;
	}
};

struct Edge
{
	int to, cost, next;

	Edge(int t = 0, int c = 0, int n = 0) : to(t), cost(c), next(n) {}

} edge[MAXM] ; // OR [MAXN << 2]
int head[MAXN];
inline void addEdge(int u, int v, int cost)
{
	static int cnt = 0;
	cnt++;
	edge[cnt] = Edge(v, cost, head[u]);
	head[u] = cnt;
}

int vis[MAXN], dis[MAXN];
priority_queue<Node, vector<Node>, greater<Node> > q;
void dij(int s)
{
	memset(dis, 0x3f, sizeof(dis));
	dis[s] = 0;
	q.push(Node(0, s));

	while (!q.empty())
	{
		Node node = q.top(); q.pop();
		int u = node.pos;
		if (vis[u]) continue;
		
		vis[u] = 1;
		for (int i = head[u]; i; i = edge[i].next)
		{
			int v = edge[i].to;
			if (dis[v] > dis[u] + edge[i].cost)
			{
				dis[v] = dis[u] + edge[i].cost;
				if (!vis[v])
				{
					q.push(Node(dis[v], v));
				}
			}
		}
	}
}


int n, m, s;

int main()
{
	scanf("%d%d%d", &n, &m, &s);
	for (int i = 0; i < m; i++)
	{
		int u, v, cost;
		scanf("%d%d%d", &u, &v, &cost);
		addEdge(u, v, cost);
		//addEdge(v, u, cost); //<-无向图
	}
	dij(s);

	for (int i = 1; i <= n; i++)
	{
		printf("%d ", (dis[i] != 0x3f3f3f3f? dis[i]: 2147483647));
	}

	return 0;
}

