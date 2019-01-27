/*

   q_pow(a, k, mod) == a ^ k (MOD mod)

 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
//typedef unsigned long long ll; //when need;

ll q_pow(ll a, ll k, ll mod)
{
	if (!k) return 1;

	ll ans = 1;
	while (k)
	{
		if (k & 1) ans = ans * a % mod;
		a = a * a % mod;
		k >>= 1;
	}
	return ans;
}

int main()
{
	return 0;
}
