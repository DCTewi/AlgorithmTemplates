/**
 * 基于pb_ds库中的tree, 可以通过extc++.h一键引用
 * 通过位移让红黑树可以插入重复的值
 */
#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> rbtree;

class Rb_Tree
{
private:
    
    const static int Offset = 20;
    rbtree _tr;
    int _ind = 1;

public:
    void add(ll x)
    {
        _tr.insert((x << Offset) + _ind);
        _ind++;
    }
    void del(ll x)
    {
        _tr.erase(_tr.lower_bound(x << Offset));
    }
    int rankof(ll x)
    {
        return _tr.order_of_key(x << Offset) + 1;
    }
    ll kth(int k)
    {
        return (*_tr.find_by_order(k - 1) >> Offset);
    }
    ll get_prev(ll x)
    {
        return (*--_tr.lower_bound(x << Offset) >> Offset);
    }
    ll get_next(ll x)
    {
        return (*_tr.lower_bound((x + 1) << Offset) >> Offset);
    }
};

Rb_Tree tr;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
    {
        ll opt, x; cin >> opt >> x;
        switch (opt)
        {
            case 1:
            {
                // Add
                tr.add(x);
            }
            break;
            case 2:
            {
                // Del
                tr.del(x);
            }
            break;
            case 3:
            {
                // Get rank
                cout << tr.rankof(x) << "\n";
            }
            break;
            case 4:
            {
                //Get kth
                cout << tr.kth(x) << "\n";
            }
            break;
            case 5:
            {
                // Get Prev
                cout << tr.get_prev(x) << "\n";
            }
            break;
            case 6:
            {
                // Get Next
                cout << tr.get_next(x) << "\n";
            }
            break;
            default: break;
        }
    }
    return 0;
}