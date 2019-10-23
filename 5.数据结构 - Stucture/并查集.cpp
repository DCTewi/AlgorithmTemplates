#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
int father[MAXN];

inline int getf(int p)
{
	return father[p] == p? p: father[p] = getf(father[p]);
}

void unite(int a, int b)
{
	if (getf(a) != getf(b)) father[getf(a)] = getf(b);
}

void initf(int maxn)
{
	for (int i = 1; i <= maxn; i++) father[i] = i;
}


int n, m;
int z, x, y;

int main()
{
	scanf("%d%d", &n, &m);
	initf(n);

	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &z, &x, &y);
		if (z == 1)
		{
			unite(x, y);
		}
		else
		{
			printf("%c\n", (getf(x) != getf(y))? 'N': 'Y');
		}
	}

	return 0;
}

