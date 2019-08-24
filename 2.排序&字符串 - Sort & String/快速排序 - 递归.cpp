#include <bits/stdc++.h>
using namespace std;

// sort() begin //

void qsort(int a[], int l, int r)
{
	if (l < r)
	{
		int i = l, j = r, x = a[l];
		while (i < j)
		{
			while (i < j && a[j] >= x) j--;
			if (i < j) a[i++] = a[j];
			
			while (i < j && a[i] < x) i++;
			if (i < j) a[j--] = a[i];
		}
		a[i] = x;

		qsort(a, l, i - 1);
		qsort(a, i + 1, r);
	}
}

// sort() end //

int main(int argc, char const *argv[])
{
	int a[] = {9, 2, 5, 12, 3, 233};
	int len = sizeof(a) / sizeof(int);
	qsort(a, 0, len - 1);

	for (int i : a) cout<<i<<" ";

	return 0;
}
