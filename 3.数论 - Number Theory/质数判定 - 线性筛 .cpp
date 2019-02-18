#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e7 + 5;

//check[n] == 0 means n is a prime.
//prim[0..top - 1] are primes below upLimit
int check[MAXN];
int prim[MAXN], top = 0;

void getPrime(int upLimit)
{
	check[0] = check[1] = 1;
	for (int i = 2; i <= upLimit; i++)
	{
		if (!check[i])
		{
			prim[top++] = i;
		}

		for (int j = 0; j < top; j++)
		{
			if (i * prim[j] > upLimit) break;

			check[i * prim[j]] = 1;

			if (i % prim[j] == 0) break;
		}
	}
	return ;
}

int main(int argc, char const *argv[])
{
	getPrime(200);
	cout<<"Top: "<<top<<endl;
	for (int i = 0; i < top; i++)
	{
		cout<<prim[i]<<" ";

		if (!(i % 10)) cout<<endl;
	}
	cout<<endl;
	return 0;
}

