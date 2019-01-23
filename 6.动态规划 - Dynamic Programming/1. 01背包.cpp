/* 
 * 01背包: n件物品 m容量 v[]价值 w[]费用
 */

//无优化：
for(int i = 1; i <= n; i++)
{
    for(int c = 0; c <= m; c++)
    {
        f[i][c] = f[i-1][c];
        if(c >= w[i])
        f[i][c] = max(f[i][c], f[i-1][c-w[i]] + v[i]);
    }
}

//滚动数组优化：
for(int i = 1; i <= n; i++)
{
    for(int c = m; c >= 0; c--)
    {
        if(c >= w[i])
        f[c] = max(f[c], f[c - w[i]] + v[i]);
    }
}
