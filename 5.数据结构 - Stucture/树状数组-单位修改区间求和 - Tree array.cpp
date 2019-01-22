#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500000 + 5;
int n = 0, m = 0;
int c[MAXN], a[MAXN];
int opt, x, y, tmp;

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
	return ;
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
