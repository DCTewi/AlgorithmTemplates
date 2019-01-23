/*
 * Dijkstra适用于: 正权连通图
 */

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1E5 + 5;
const int MAXM = 5E5 + 5;

struct Node
{
	Node(){}
	Node(int d, int p)
	{
		this->dis = d; this->pos = p;
	}

	int dis, pos;

	bool operator>(const Node &other) const
	{
		return this->dis > other.dis;
	}
};

struct Edge
{
	int to, cost, next;

	Edge(){}
	Edge(int t, int c, int n)
	{
		this->to = t;
		this->cost = c;
		this->next = n;
	}

}edge[MAXM];

int head[MAXN], dis[MAXN], cnt = 0;
bool vis[MAXN];

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

inline void addEdge(int u, int v, int cost)
{
	cnt++;
	edge[cnt] = Edge(v, cost, head[u]);
	head[u] = cnt;
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

