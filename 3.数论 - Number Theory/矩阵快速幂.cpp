// HDU - pid=5015 - 233 Matrix
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 10000007;
const int MAXM = 1e9 + 5;
const int MAXN = 1e1 + 5;

ll n, m, a[MAXN], ans = 0;

struct Matrix
{
    ll dat[MAXN][MAXN];
    
    Matrix()
    {
        memset(dat, 0, sizeof(dat));
        for (int i = 0; i <= n + 1; i++)
        {
            dat[i][n + 1] = 1;
            if (i == n + 1) continue;
            dat[i][0] = 10;
            for (int j = 1; j <= i; j++)
            {
                dat[i][j] = 1;
            }
        }
    }

    void clear()
    {
        memset(dat, 0, sizeof(dat));
        for (int i = 0; i <= n + 1; i++)
        {
            dat[i][i] = 1;
        }
    }

    void display()
    {
        cout << "Begin here:\n";
        for (int i = 0; i <= n + 1; i++)
        {
            for (int j = 0; j <= n + 1; j++)
            {
                cout << dat[i][j] << " \n"[j == n + 1];
            }
        }
        cout << "End\n";
    }

    friend Matrix operator* (Matrix a, Matrix b)
    {
        Matrix res;
        for (int i = 0; i <= n + 1; i++)
        {
            for (int j = 0; j <= n + 1; j++)
            {
                res.dat[i][j] = 0;
                for (int k = 0; k <= n + 1; k++)
                {
                    res.dat[i][j] += a.dat[i][k] * b.dat[k][j] % MOD;
                }
            }
        }
        return res;
    }

    friend Matrix operator^ (Matrix base, ll k)
    {
        Matrix res;
        res.clear();
        while (k)
        {
            if (k & 1) res = res * base;
            base = base * base;
            k >>= 1;
        }
        return res;
    }
};

int main()
{
    while (~scanf("%lld%lld", &n, &m))
    {
        Matrix base; ans = 0;
        a[0] = 23; a[n + 1] = 3;
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &a[i]);
        }
        base = base ^ m;

        for (int i = 0; i <= n + 1; i++)
        {
            ans += a[i] * base.dat[n][i];
        }
        printf("%lld\n", ans % MOD);
    }
    
    return 0;
}
