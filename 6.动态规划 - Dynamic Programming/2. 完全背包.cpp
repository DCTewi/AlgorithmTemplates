/*
 * 完全背包: n种物品 m容量 w[]费用 v[]价值
 */
 
for (int i = 1; i <= n; i++)
{
	for (int c = 0; c <= m; c++)
	{
		if (c >= w[i])
		{
			f[c] = max(f[c], f[c - w[i]] + v[i]);
		}
	}
}

