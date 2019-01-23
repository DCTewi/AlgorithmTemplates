/*
 * add(p, delta) 表示将点p增加delta
 * sum(p) 表示从p到n的和
 */

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500000 + 5;
int c[MAXN], a[MAXN], n = 0;

inline int lowbit(int p)
{
	return p & (-p);
}

void add(int p, int delta)
{
	a[p] += delta;
	for (; p <= n; p += lowbit(p))
	{
		c[p] += delta;
	}
}

int sum(int p)
{
	int ans = 0;
	for (; p > 0; p -= lowbit(p))
	{
		ans += c[p];
	}
	return ans;
}

int m, opt, x, y, tmp;

int main()
{
	cin>>n>>m;
	for (int i = 1; i <= n; i++)
	{
		cin>>tmp;
		add(i, tmp);
	}
	
	for (int t = 0; t < m; t++)
	{
		cin>>opt>>x>>y;
		if (opt == 1)
		{
			add(x, y);
		}
		else
		{
			x == 1?
				cout<<sum(y)<<endl:
				cout<<sum(y) - sum(x-1)<<endl;
		}
	}
	
	return 0;
}

