/*
 * 多重背包，01背包和完全背包的"结合"
 * n种物品, 每种物品有费用w[n],价值v[n],和数量num[n]
 * 背包容量m
 * 一种解法: 通过将每种物品的数量展开来转换成01背包问题
 */

int k = n + 1;
for (int i = 1; i <= n; i++)
{
	for (; num[i] > 1; num[i]--)
	{
		w[k] = w[i]; v[k] = v[i];
		k++;
		num[i]--;
	}
}

for (int i = 1; i <= k; i++)
{
	for (int j = m; j >= 1; j--)
	{
		if (w[i] <= j)
		{
			f[j] = max(f[j], f[j - w[i]] + v[i]);
		}
	}
}

