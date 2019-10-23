#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e3 + 5;

struct BIT_2D
{
    int n, m;
    ll c1[MAXN][MAXN], c2[MAXN][MAXN], c3[MAXN][MAXN], c4[MAXN][MAXN];
    int lowbit(int x)
    {
        return x & (-x);
    }
    
    BIT_2D(int n, int m): n(n), m(m)
    {
        memset(c1, 0, sizeof(c1));
        memset(c2, 0, sizeof(c2));
        memset(c3, 0, sizeof(c3));
        memset(c4, 0, sizeof(c4));
    }

    void addsum(int x, int y, ll delta)
    {
        for (int i = x; i <= n; i += lowbit(i))
        {
            for (int j = y; j <= m; j += lowbit(j))
            {
                c1[i][j] += delta;
                c2[i][j] += delta * x;
                c3[i][j] += delta * y;
                c4[i][j] += delta * x * y;
            }
        }
    }
    void add(int xl, int yl, int xr, int yr, ll delta)
    {
        addsum(xl, yl, delta);
        addsum(xl, yr + 1, -delta);
        addsum(xr + 1, yl, -delta);
        addsum(xr + 1, yr + 1, delta);
    }

    ll sumall(int x, int y)
    {
        ll res = 0;
        for (int i = x; i > 0; i -= lowbit(i))
        {
            for (int j = y; j > 0; j -= lowbit(j))
            {
                res += (x + 1) * (y + 1) * c1[i][j];
                res -= (y + 1) * c2[i][j] + (x + 1) * c3[i][j];
                res += c4[i][j];
            }
        }
        return res;
    }
    ll sum(int xl, int yl, int xr, int yr)
    {
        return sumall(xr, yr) 
        - sumall(xl - 1, yr) 
        - sumall(xr, yl - 1) 
        + sumall(xl - 1, yl - 1);
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

    return 0;
}
