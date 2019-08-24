#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

// miller rabin begin //

const int TIMES = 20; //Test times;

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

ll random(ll n)
{
	return ((double)rand() / RAND_MAX * n + 0.5);
}

bool witness(ll a, ll n) //Check witness
{
	ll tem = n - 1;
	int j = 0;
	while (!(tem & 1))
	{
		tem /= 2;
		j++;
	}
	// n - 1 => a ^ r * s
	ll x = q_pow(a, tem, n);
	if (x == 1 || x == n - 1) return true;

	while (j--)
	{
		x = q_mul(x, x, n);
		if (x == n - 1) return true;
	}
	return false;
}

bool miller_rabin(ll p) //Generate random a to check if there is a witness of p.
{
	if (p == 2) return true;
	if (p < 2 || !(p & 1)) return false;

	for (int i = 1; i < TIMES; i++)
	{
		ll a = random(p - 2) + 1;
		if (!witness(a, p))
		{
			return false;
		}
	}

	return true;
}

// miller rabin end //

int main()
{
	ll n; cin>>n;

	if (miller_rabin(n))
	{
		puts("It's a prime.");
	}
	else
	{
		puts("It's not a prime.");
	}

	return 0;
}

