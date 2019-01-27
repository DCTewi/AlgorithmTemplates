/*
   
   q_mul(a, b, mod) == a * b (MOD mod);

 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
//typedef unsigned long long ll; //when need;

ll q_mul(ll a, ll b, ll mod)
{
	if (!b) return 0;

	ll ans = 0;
	while (b)
	{
		if (b & 1) ans = (ans + a) % mod;
		a = (a + a) % mod;
		b >>= 1;
	}
	return ans;
}

int main()
{
	return 0;
}

