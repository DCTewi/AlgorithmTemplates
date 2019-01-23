/*
 *
 *	Just use python.
 *
 */

#include <bits/stdc++.h>
using namespace std;

#ifndef TEWIBIGINT

const int MAXN = 1e3 + 5;
class BigInt
{
public:
	BigInt()
	{
		memset(this->d, 0, sizeof(d));
	}
	BigInt(string str)
	{
		this->len = str.size();
		for (int i = 0; i < this->len; i++)
		{
			this->d[i] = str[this->len - 1 - i] - '0';
		}
	}

	int d[MAXN], len = 0;

	static int Compare(BigInt a, BigInt b)
	{
		if (a.len > b.len) return 1; // a > b
		else if (a.len < b.len) return -1; // a < b
		else 
		{
			for (int i = a.len - 1; i >= 0; i++)
			{
				if (a.d[i] > b.d[i]) return 1;
				else if (a.d[i] < b.d[i]) return -1;
			}
		}
		return 0; // a == b
	}

	static BigInt Add(BigInt a, BigInt b)
	{
		BigInt ans;
		int delta = 0;
		for (int i = 0; i < a.len || i < b.len; i++)
		{
			int temp = a.d[i] + b.d[i] + delta;
			ans.d[ans.len++] = temp % 10;
			delta = temp / 10;
		}
		if (delta != 0)
		{
			ans.d[ans.len++] = delta;
		}
		return ans;
	}

	static BigInt Minus (BigInt a, BigInt b)
	{
		/* Wait for Update */
	}

	bool operator<(const BigInt &other) const
	{
		return Compare(*this, other) == -1;
	}

	bool operator>(const BigInt &other) const
	{
		return Compare(*this, other) == 1;
	}

	bool operator==(const BigInt &other) const
	{
		return Compare(*this, other) == 0;
	}

	bool operator<=(const BigInt &other) const
	{
		return Compare(*this, other) <= 0 ;
	}

	bool operator>=(const BigInt &other) const
	{
		return Compare(*this, other) >= 0 ;
	}

	BigInt operator+(const BigInt &other) const
	{
		return Add(*this, other);
	}
};

ostream& operator<<(ostream &os, const BigInt c)
{
	for (int i = c.len - 1; i >= 0; i--)
	{
		os<<c.d[i];
	}
	return os;
}

istream& operator>>(istream &ins, BigInt &c)
{
	string temp; ins>>temp; c = BigInt(temp);
	return ins;
}

#endif

int main(int argc, char const *argv[])
{
	BigInt a;
	BigInt b = BigInt("456");

	cout<<b.len<<endl;
	cout<<b<<endl;

	cout<<BigInt("111") + BigInt("222")<<endl;

	cin>>a;
	cout<<a<<endl;

	cout<<a + b<<endl;

	return 0;
}

