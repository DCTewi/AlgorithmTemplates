#include <bits/stdc++.h>
using namespace std;

/*
 * int i = read();
 */

inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while (!isdigit(ch))
	{
		w |= ch == '-'; ch = getchar();
	}
	while (isdigit(ch))
	{
		x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar();
	}
	return w? -x: x;
}

/*
 * double d = readDbl();
 */

inline double readDbl()
{
	double x = 0, p = 1.0f; int w = 0; char ch = getchar();
	while (!isdigit(ch))
	{
		w |= ch == '-'; ch = getchar();
	}
	while (isdigit(ch))
	{
		x = x * 10 + (ch ^ 48); ch = getchar();
	}
	ch = getchar();
	while (isdigit(ch))
	{
		x += (p /= 10) * (ch ^ 48); ch = getchar();
	}
	return w? -x: x;
}

/*
 * print(i);
 */

inline void print(int x)
{
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

int main(int argc, char const *argv[])
{
	return 0;
}
