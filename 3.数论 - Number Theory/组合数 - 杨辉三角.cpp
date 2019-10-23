typedef long long ll;
const int MAXN = 1e4 + 5;
ll c[MAXN][MAXN];
void getC(int uplimit)
{
    c[0][0] = c[1][0] = c[1][1] = 1;
    for (int i = 2; i <= uplimit; i++)
    {
        c[i][0] = 1;
        for (int j = 1; j <= i; i++)
        {
            c[i][j] = c[i][j - 1] + c[i - 1][j - 1];
        }
    }
}
