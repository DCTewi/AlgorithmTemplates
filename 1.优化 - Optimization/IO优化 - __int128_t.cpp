#include <bits/stdc++.h>
using namespace std;
typedef __int128_t bigint;
typedef __uint128_t ubigint;

const int MAXN = 8e1 + 5;

inline void read128(__int128_t &x)
{
    int w = 0; char ch = getchar(); x = 0;
    while (!isdigit(ch))
    {
        w |= ch == '-'; ch = getchar();
    }
    while (isdigit(ch))
    {
        x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar();
    }
    x = w? -x: x;
}

inline void print128(__int128_t x)
{
    if (x < 0)
    {
        putchar('-'); x = -x;
    }
    if (x > 9) print128(x / 10);

    putchar(x % 10 + '0');
}

int main()
{
    bigint a, b;

    read128(a); read128(b);

    print128(a + b);

    return 0;
}
