#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline ll gcd(int a, int b)
{
    return b? gcd(a, a % b): a;
}

inline ll lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if (!b)
    {
        x = 1; y = 0; return a;
    }
    ll r = exgcd(b, a % b, x, y);
    ll tem = y;
    y = x - a / b * y;
    x = tem;
    return r;
}

int main()
{
    return 0;
}