#include <bits/stdc++.h>
using namespace std;

// Int128 begin //

typedef __int128_t bigint;
typedef __uint128_t ubigint;
namespace Int128
{
    inline void read(__int128_t &x, ...)
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

    inline void print(__int128_t x)
    {
        if (x < 0)
        {
            putchar('-'); x = -x;
        }
        if (x > 9) print(x / 10);

        putchar(x % 10 + '0');
    }
}

// Int128 end //

int main()
{
    bigint a, b;
    Int128::read(a); Int128::read(b);
    Int128::print(a + b);
    return 0;
}
