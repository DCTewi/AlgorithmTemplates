/*
 * add(p, delta) 表示将从p到n的所有数的变化量增加delta
 * sum(p) 返回a[p]的 >变化量<
 */

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 50;
int a[MAXN], c[MAXN], n = 0;

inline int lowbit(int i)
{
	return i & (-i);
}

void add(int p, int delta)
{
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
					add(x, k);
					add(y + 1, -k);
					break;
				}
			case 2:
				{
					cin>>x;
					printf("%d\n", a[x] + sum(x));
					break;
				}
		}
	}
	return 0;
}

