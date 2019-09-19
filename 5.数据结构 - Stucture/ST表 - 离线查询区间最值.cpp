#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

template <class T> T read()
{
    T x = 0; int w = 0, ch = getchar();
    while (!isdigit(ch)) w |= ch == '-', ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return w? -x: x;
}

const int MAXN = 2e6 + 5;
const int LOGN = 21;

int logn[MAXN];

struct SparseTable
{
    int (*f)[LOGN] = new int[MAXN][LOGN];

    static void init()
    {
        logn[0] = logn[1] = 0;
        logn[2] = 1;
        for (int i = 3; i < MAXN; i++)
        {
            logn[i] = logn[i / 2] + 1;
        }
    }

    ~SparseTable()
    {
        delete []f;
    }

    SparseTable(vector<int> &raw)
    {
        int n = raw.size();
        for (int i = 1; i <= n; i++)
        {
            f[i][0] = raw[i - 1];
        }
        for (int j = 1; j <= LOGN; j++)
        {
            for (int i = 1; i + (1 << j) - 1 <= n; i++)
            {
                f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int query(const int l, const int r)
    {
        int s = logn[r - l + 1];
        return max(f[l][s], f[r - (1 << s) + 1][s]);
    }
};

int main()
{
    int n = read<int>(), m = read<int>();
    vector<int> raw(n);
    for (int i = 0; i < n; i++)
    {
        raw[i] = read<int>();
    }

    SparseTable::init();
    SparseTable st(raw);

    for (int i = 0; i < m; i++)
    {
        int l = read<int>(), r = read<int>();
        printf("%d\n", st.query(l, r));
    }

    return 0;
}


