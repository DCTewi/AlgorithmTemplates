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

rbtree tr;

int main()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
    {
        ll opt, x; cin >> opt >> x;
        switch (opt)
        {
            case 1:
            {
                // Add
                tr.insert((x << 20) + i);
            }
            break;
            case 2:
            {
                // Del
                tr.erase(tr.lower_bound(x << 20));
            }
            break;
            case 3:
            {
                // Get rank
                cout << tr.order_of_key(x << 20) + 1 << "\n";
            }
            break;
            case 4:
            {
                //Get kth
                cout << (*tr.find_by_order(x - 1) >> 20) << "\n";
            }
            break;
            case 5:
            {
                // Get Prev
                cout << (*--tr.lower_bound(x << 20) >> 20) << "\n";
            }
            break;
            case 6:
            {
                // Get Next
                cout << (*tr.lower_bound((x + 1) << 20) >> 20) << "\n";
            }
            break;
            default: break;
        }
    }
    return 0;
}