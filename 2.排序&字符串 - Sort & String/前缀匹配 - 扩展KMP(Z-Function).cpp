#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// z_func begin //

vector<int> z_func(string &s)
{
    int n = (int)s.size();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i)
    {
        if (i <= r) z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    return z;
}

// z_func end //

int main()
{
    string s; cin >> s;
    auto z = z_func(s);
    for (auto i : z)
    {
        cout << i << " ";
    }
    cout << "\n";

    return 0;
}

