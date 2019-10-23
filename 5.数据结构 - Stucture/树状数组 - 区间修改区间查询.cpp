#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 5e5 + 5;

struct BIT
{
    int cnt;
    ll c[MAXN], c2[MAXN]; // For d[i], d[i] * i
    inline int lowbit(int x)
    {
        return x & (-x);
    }

    BIT(int n) : cnt(n)
    {
        memset(c, 0, sizeof(c));
        memset(c2, 0, sizeof(c2));
    }

    void addall(int p, ll delta)
    {
        for (int i = p; i <= cnt; i += lowbit(i))
        {
            c[i] += delta; c2[i] += delta * p;
        }
    }
    void add(int l, int r, ll delta)
    {
        addall(l, delta); addall(r + 1, -delta);
    }

    ll sumall(int p)
    {
        ll res = 0;
        for (int i = p; i > 0; i -= lowbit(i))
        {
            res += (p + 1) * c[i] - c2[i];
        }
        return res;
    }
    ll sum(int l, int r)
    {
        return sumall(r) - sumall(l - 1);
    }
};

template <class T> T read()
{
    T x = 0; int w = 0, ch = getchar();
    while (!isdigit(ch)) w |= ch == '-', ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48),  ch = getchar();
    return w? -x: x;
}

int main()
{
    int n = read<int>(), m = read<int>();
    BIT bit(n);
    for (int i = 1; i <= n; i++)
    {
        int x = read<int>();
        bit.add(i, i, x);
    }

    for (int i = 0; i < m; i++)
    {
        int opt = read<int>();
        if (opt == 1)
        {
            int x = read<int>(), y = read<int>(), k = read<int>();
            bit.add(x, y, k);
        }
        else if (opt == 2)
        {
            int x = read<int>();
            printf("%lld\n", bit.sum(x, x));
        }
    } 
    return 0;
}
