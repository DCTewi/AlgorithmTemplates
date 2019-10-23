#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e5 + 5;
const int MXN = 5e3 + 5;

int n, m;

struct Edge
{
	int p1, p2, cost;
	Edge(int P1 = 0, int P2 = 0, int C = 0) : p1(P1), p2(P2), cost(C) {}

} edge[MAX] ;

int father[MXN];
inline int getf(int p)
{
	return father[p] == p? p: father[p] = getf(father[p]);
}

inline void unite(int a, int b)
{
	father[getf(a)] = getf(b);
}

int mst = 0, cnt = 0;
bool kruskal()
{
	for (int i = 1; i <= n; i++) father[i] = i;
	sort(edge + 1, edge + 1 + m, [](const Edge &a, const Edge &b)->bool
	{
		return a.cost < b.cost;
	});
	cnt = n;
	for (int i = 1; i <= m; i++)
	{
		if (!n) break;
		int &u = edge[i].p1, &v = edge[i].p2;
		
		if (getf(u) != getf(v))
		{
			unite(u, v);
			mst += edge[i].cost;
			cnt--;
		}
	}
	return cnt == 1;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &edge[i].p1, &edge[i].p2, &edge[i].cost);
	}
	
	if (!kruskal()) puts("orz");
	else cout << mst << "\n";
	
	return 0;
}
