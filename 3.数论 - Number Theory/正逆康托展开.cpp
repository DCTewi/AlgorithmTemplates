#include <bits/stdc++.h>
using namespace std;

const int FACT[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
int cantor(const vector<int> &a)
{
    int res (0);
    int len (a.size());
    for (int i = 0; i < len; i++)
    {
        int num = 0;
        for (int j = i + 1; j < len; j++)
        {
            if (a[j] < a[i]) num++;
        }
        res += FACT[len - i - 1] * num;
    }
    return res;
}
vector<int> decantor(int x, int n)
{
    vector<int> vis, res;
    for (int i = 0; i <= n; i++) vis.emplace_back(i + 1);
    for (int i = n - 1; i >= 0; i--)
    {
        int now = x / FACT[i];
        x %= FACT[i];

        res.emplace_back(vis[now]);
        vis.erase(vis.begin() + now);
    }
    return res;
}

int main()
{
    auto a = {3, 4, 1, 5, 2};
    int ct = cantor(a);
    cout << ct << "\n";

    auto b = decantor(ct, 5);
    for (int i : b) cout << i << " "; cout << "\n";

    return 0;
}
