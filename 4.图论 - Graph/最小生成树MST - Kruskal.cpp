#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e5 + 5;
const int MXN = 5e3 + 5;
struct Edge
{
	int p1, p2, cost;
	
	bool operator<(const Edge &other) const
	{
		return (*this).cost < other.cost;
	}
	
	Edge(int P1 = 0, int P2 = 0, int C = 0):p1(P1), p2(P2), cost(C){}
}edge[MAX];
int father[MXN];
int mst = 0,  cnt = 0;
int n, m;

int getf(int p)
{
	if (father[p] != p)
	{
		father[p] = getf(father[p]);
	}
	return father[p];
}

inline void unite(int a, int b)
{
	father[getf(a)] = getf(b);
	return ;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &edge[i].p1, &edge[i].p2, &edge[i].cost);
	}
	for (int i = 1; i <= n; i++)
	{
		father[i] = i;
	}
	
	sort(edge + 1, edge + 1 + m);
	cnt = n;
	
	for (int i = 1; i <= m; i++)
	{
		if (!n) break;
		
		int u = edge[i].p1;
		int v = edge[i].p2;

		if (getf(u) != getf(v))
		{
			unite(u, v);
			mst += edge[i].cost;
			cnt--;
		}
	}
	
	if (cnt != 1)
	{
		printf("orz\n");
	}
	else
	{
		printf("%d\n", mst);
	}
	
	return 0;
}
