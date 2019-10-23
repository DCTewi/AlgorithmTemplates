#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template <class T> T read();

const int MAXN = 2e5 + 5;

struct SegTree
{
    struct SegNode
    {
        int l = 0, r = 0;
        ll data = 0, tag = 0;
    };
    static inline int lson(int p){return p << 1;}
    static inline int rson(int p){return p << 1 | 1;}

    vector<SegNode> st;
    int n;

    explicit SegTree(int n = MAXN, vector<int> raw = {}) : n(n)
    {
        st = vector<SegNode>((n << 2) + 2);
        build(raw, 1, n);
    }

    void push_up(int p)
    {
        st[p].data = max(st[lson(p)].data, st[rson(p)].data);
    }

    void lazy_down(int p)
    {
        if (st[p].tag)
        {
            st[lson(p)].tag += st[p].tag;
            st[rson(p)].tag += st[p].tag;
            st[lson(p)].data += st[p].tag;
            st[rson(p)].data += st[p].tag;
            st[p].tag = 0;
        }
    }

    void build(vector<int> &raw, int l, int r, int p = 1)
    {
        st[p].l = l, st[p].r = r;
        if (l == r)
        {
            st[p].data = ((int)raw.size() >= l)? raw[l - 1]: 0; return;
        }

        int mid = (l + r) >> 1;
        build(raw, l, mid, lson(p));
        build(raw, mid + 1, r, rson(p));

        push_up(p);
    }

    void add(int l, int r, ll k, int p = 1)
    {
        if (st[p].l >= l && st[p].r <= r)
        {
            st[p].data += k;
            st[p].tag += k;
            return;
        }
        lazy_down(p);

        int mid = (st[p].l + st[p].r) >> 1;
        if (mid >= l) add(l, r, k, lson(p));
        if (mid <  r) add(l, r, k, rson(p));

        push_up(p);
    }

    ll query(int l, int r, int p = 1)
    {
        if (st[p].l >= l && st[p].r <= r) return st[p].data;

        lazy_down(p);
        ll ans = 0;
        int mid = (st[p].l + st[p].r) >> 1;
        if (mid >= l) ans = max(ans, query(l, r, lson(p)));
        if (mid <  r) ans = max(ans, query(l, r, rson(p)));

        return ans;
    }
};

int main()
{
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        vector<int> raw(n);
        for (int i = 0; i < n; i++)
        {
            raw[i] = read<int>();
        }
        SegTree st(n, raw);

        for (int i = 0; i < m; i++)
        {
            char opt; cin >> opt;
            int x = read<int>(), y = read<int>();
            switch (opt)
            {
                case 'Q':
                {
                    printf("%lld\n", st.query(x, y));
                    break;
                }
                case 'U':
                {
                    st.add(x, x, -st.query(x, x));
                    st.add(x, x, y);
                    break;
                }
            }
        }

    }

    return 0;
}