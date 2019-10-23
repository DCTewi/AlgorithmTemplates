/*
 * add(l, r, delta) 表示将[l, r]的所有数的变化量增加delta
 * sum(p) 返回a[p]
 */

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 50;
int a[MAXN], c[MAXN], n = 0;

inline int lowbit(int i)
{
	return i & (-i);
}

void addall(int p, int delta)
{
	for (; p <= n; p += lowbit(p))
	{
		c[p] += delta;
	}
}

void add(int l, int r, int delta)
{
	addall(l, delta); addall(r + 1, -delta);
}

int sum(int p)
{
	int ans = a[p];
	for (; p > 0; p -= lowbit(p))
	{
		ans += c[p];
	}

	return ans;
}

int m = 0;
int opt, x, y, k;

int main()
{
	cin>>n>>m;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int t = 1; t <= m; t++)
	{
		cin>>opt;
		switch (opt)
		{
			case 1:
				{
					cin>>x>>y>>k;
					add(x, y, k);
					break;
				}
			case 2:
				{
					cin>>x;
					printf("%d\n", sum(x));
					break;
				}
		}
	}
	return 0;
}

