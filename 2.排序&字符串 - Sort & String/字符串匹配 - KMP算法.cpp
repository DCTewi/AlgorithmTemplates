/*
	Passed  https://www.luogu.org/problemnew/show/P3375
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e6 + 5;
ll nxt[MAXN];

void getNext(string s/*, int *nxt */)
{
	nxt[0] = -1; // -1 表示前后缀不存在
	int k = -1; // 模式串的匹配游标
	for (int i = 1; i < s.size(); i++)
	{
		while (k != -1 && s[k + 1] != s[i]) k = nxt[k];
		//下一个数失配则更新本位的失配指针，k == -1则触顶
		if (s[k + 1] == s[i]) k++;
		nxt[i] = k;
	}
}

void kmp(string s, string p)
{
	getNext(p);
	int k = -1;
	for (int i = 0; i < s.size(); i++)
	{
		while (k != -1 && p[k + 1] != s[i]) k = nxt[k];
		//下一位失配则移动游标 <=> 移动模式串
		if (p[k + 1] == s[i]) k++; //匹配成功，后移游标
		if (k == p.size() - 1)
		{
			//找到某个匹配结果
			k = nxt[k]; //继续向后匹配
			/* Custom code*/

				cout<<i - p.size() + 2<<endl; //输出模式串开始位置
				//+2分别是位置坐标补正和减法补正:wq

			/* Custom code end*/
		}
	}
}

int main()
{
	string str1, str2; cin>>str1>>str2;

	kmp(str1, str2);

	for (int i = 0; i < str2.size(); i++)
	{
		cout<<nxt[i] + 1<<" ";
	}
	cout<<endl;

	return 0;
}
