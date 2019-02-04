#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;

// IO optimization
template <typename ty>
inline void read(ty &x)
{
	x = 0; int w = 0; char ch = getchar();
	while (!isdigit(ch))
	{
		w |= ch == '-'; ch = getchar();
	}
	while (isdigit(ch))
	{
		x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar();
	}
}

// Segment tree main part
ll st[MAXN << 2], add[MAXN << 2];
int n, N = 1;

inline void build()
{
	for (; N < n + 1; N <<= 1); // Get raw data's place.
	for (int i = N + 1; i <= N + n; i++) read(st[i]); // Raw data.
	for (int i = N - 1; i >= 1; i--) st[i] = st[i << 1] + st[i << 1 | 1]; // Build from leaves.
}

inline void update(int l, int r, ll k)
{
	int s = N + l - 1, t = N + r + 1; // Left and Right.
	ll lNum = 0, rNum = 0, num = 1; // how many k left contained = lNum, how many k this plate contained = num.
	for (; s ^ t ^ 1; s >>= 1, t >>= 1, num <<= 1) // If s and t has same father, s ^ t == 1, 1 ^ 1 == 0
	{
		st[s] += k * lNum;
		st[t] += k * rNum;
		if (~s & 1) {add[s ^ 1] += k; st[s ^ 1] += k * num; lNum += num;} // If s is the left kid of its father, add its brother node.
		if ( t & 1) {add[t ^ 1] += k; st[t ^ 1] += k * num; rNum += num;} // If t is the right kid of its father, add its brother node.
	}
	for (; s; s >>= 1, t >>= 1) // Up to root
	{
		st[s] += k * lNum;
		st[t] += k * rNum;
	}
}

inline ll query(int l, int r)
{
	int s = N + l - 1, t = N + r + 1; // Left and Right.
	ll lNum = 0, rNum = 0, num = 1, ans = 0; // Same as update()#lNum.
	for (; s ^ t ^ 1; s >>= 1, t >>= 1, num <<= 1)
	{
		if (add[s]) ans += add[s] * lNum; // Add the add lazy tag.
		if (add[t]) ans += add[t] * rNum;
		if (~s & 1) {ans += st[s ^ 1]; lNum += num;}
		if ( t & 1) {ans += st[t ^ 1]; rNum += num;}
	}
	for (; s; s >>= 1, t >>= 1) // Up to root
	{
		ans += add[s] * lNum;
		ans += add[t] * rNum;
	}
	return ans;
}

// For luogu p3372
int main(int argc, char const *argv[])
{
	int m; read(n); read(m);
	build();

	for (int i = 0; i < m; i++)
	{
		int opt; read(opt);
		switch (opt)
		{
			case 1:
			{
				int x, y, k; read(x); read(y); read(k);
				update(x, y, k);
				break;
			}
			case 2:
			{
				int x, y; read(x); read(y);
				printf("%lld\n", query(x, y));
				break;
			}
		}
	}

	return 0;
}
