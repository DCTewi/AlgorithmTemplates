//Luogu p3373
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;

int n, m, mod;
ll rawdata[MAXN];

struct SegTree
{
    class SegmentTreeNode
    {
    public:
        SegmentTreeNode(){}

        int l, r;
        ll data, add_tag = 0, mul_tag = 1;
    } st[4 * MAXN + 2];

    static inline int lson(int p){return p << 1;}
    static inline int rson(int p){return p << 1 | 1;}

    void push_up(int p)
    {
        st[p].data = (st[lson(p)].data + st[rson(p)].data) % mod;
    }

    void build(int p, int l, int r)
    {
        st[p].l = l; st[p].r = r;

        if (l == r)
        {
            st[p].data = raw_data[l];
            return ;
        }

        int mid = (l + r) >> 1;
        build(lson(p), l, mid);
        build(rson(p), mid + 1, r);

        push_up(p);
    }

    void lazy_down(int p)
    {
        if (st[p].add_tag || st[p].mul_tag != 1)
        {
            st[lson(p)].data = st[lson(p)].data * st[p].mul_tag % mod;
            st[lson(p)].mul_tag = st[lson(p)].mul_tag * st[p].mul_tag % mod;
            st[lson(p)].add_tag = st[lson(p)].add_tag * st[p].mul_tag % mod;

            st[rson(p)].data = st[rson(p)].data * st[p].mul_tag % mod;
            st[rson(p)].mul_tag = st[rson(p)].mul_tag * st[p].mul_tag % mod;
            st[rson(p)].add_tag = st[rson(p)].add_tag * st[p].mul_tag % mod;

            st[p].mul_tag = 1;

            st[lson(p)].add_tag +=st[p].add_tag;
            st[lson(p)].data += st[p].add_tag * (st[lson(p)].r - st[lson(p)].l + 1);
            st[rson(p)].add_tag +=st[p].add_tag;
            st[rson(p)].data += st[p].add_tag * (st[rson(p)].r - st[rson(p)].l + 1);

            st[p].add_tag = 0;
        }
    }

    void add(int p, int l, int r, ll k)
    {
        if (st[p].l >= l && st[p].r <= r)
        {
            st[p].data = (st[p].data + k * (st[p].r - st[p].l + 1)) % mod;
            st[p].add_tag += k;
            return ;
        }

        lazy_down(p);

        int mid = (st[p].l + st[p].r) >> 1;
        if (mid >= l) add(lson(p), l, r, k);
        if (mid <  r) add(rson(p), l, r, k);

        push_up(p);
    }

    void mul(int p, int l, int r, ll k)
    {
        if (st[p].l >= l && st[p].r <= r)
        {
            st[p].data = st[p].data * k % mod;
            st[p].mul_tag = st[p].mul_tag * k % mod;
            st[p].add_tag = st[p].add_tag * k % mod;
            return ;
        }

        lazy_down(p);

        int mid = (st[p].l + st[p].r) >> 1;
        if (mid >= l) mul(lson(p), l, r, k);
        if (mid <  r) mul(rson(p), l, r, k);

        push_up(p);
    }

    long long query(int p, int l, int r)
    {
        if (st[p].l >= l && st[p].r <= r) return st[p].data % mod;

        lazy_down(p);

        ll ans = 0;
        int mid = (st[p].l + st[p].r) >> 1;
        if (mid >= l) ans += query(lson(p), l, r);
        if (mid <  r) ans += query(rson(p), l, r);

        return ans;
    }
} st ;

int main(int argc, char const *argv[])
{

    scanf("%d%d%d", &n, &m, &mod);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &raw_data[i]);
    }
    st build(1, 1, n);

    for (int i = 0; i < m; i++)
    {
        int cmd;
        scanf("%d", &cmd);
        switch (cmd)
        {
            case 1:
            {
                int x, y, k;
                scanf("%d%d%d", &x, &y, &k);
                st.mul(1, x ,y, k);
                break;
            }
            case 2:
            {
                int x, y, k;
                scanf("%d%d%d", &x, &y, &k);
                st.add(1, x, y, k);
                break;
            }
            case 3:
            {
                int x, y;
                scanf("%d%d", &x, &y);
                printf("%lld\n", st.query(1, x, y) % mod);
                break;
            }
        }
    }
    
    return 0;
}
