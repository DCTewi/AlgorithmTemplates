# 目录

[TOC]

# 1.优化 - Optimization

## IO优化 - int, double.cpp

```cpp

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

template <typename ty>
inline void read(ty &x)
{
	x = 0; int w = 0; char ch = getchar();
	while (!isdigit(ch))
	{
		w |= ch == '-'; ch = getchar();
	}
	while (isdigit(ch))
	{
		x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar();
	}
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
	int a = read(); long long b = read();
	cout<<a<<endl<<b<<endl;
	read(a); read(b);
	cout<<a<<endl<<b<<endl;
	return 0;
}
```

## IO优化 - __int128_t.cpp

```cpp

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
```

## 输入优化-奇妙.cpp

```cpp

char ch,B[1<<20],*S=B,*T=B;
#define getc() (S==T&&(T=(S=B)+fread(B,1,1<<20,stdin),S==T)?0:*S++)
#define isd(c) (c>='0'&&c<='9')
ll aa;ll F()
{ //positive only.
    while(ch=getc(),!isd(ch));aa=ch-'0';
    while(ch=getc(),isd(ch))aa=aa*10+ch-'0';
	return aa;
}

```

# 2.排序&字符串 - Sort & String

## 字符串匹配 - KMP算法.cpp

```cpp

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
```

## 快速排序 - 递归.cpp

```cpp

#include <bits/stdc++.h>
using namespace std;

// sort() (雾)

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

int main(int argc, char const *argv[])
{
	int a[] = {9, 2, 5, 12, 3, 233};

	int len = sizeof(a) / sizeof(int);
	qsort(a, 0, len - 1);

	for (int i : a)
	{
		cout<<i<<" ";
	}

	return 0;
}
```

# 3.数论 - Number Theory

## 快速乘.cpp

```cpp

/*
   
   q_mul(a, b, mod) == a * b (MOD mod);

 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
//typedef unsigned long long ll; //when need;

ll q_mul(ll a, ll b, ll mod)
{
	if (!b) return 0;

	ll ans = 0;
	while (b)
	{
		if (b & 1) ans = (ans + a) % mod;
		a = (a + a) % mod;
		b >>= 1;
	}
	return ans;
}

int main()
{
	return 0;
}

```

## 快速幂.cpp

```cpp

/*

   q_pow(a, k, mod) == a ^ k (MOD mod)

 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
//typedef unsigned long long ll; //when need;

ll q_pow(ll a, ll k, ll mod)
{
	if (!k) return 1;

	ll ans = 1;
	while (k)
	{
		if (k & 1) ans = ans * a % mod;
		a = a * a % mod;
		k >>= 1;
	}
	return ans;
}

int main()
{
	return 0;
}
```

## 质数判定 - Miller-Rabin素性判定.cpp

```cpp

#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

const int TIMES = 20; //Test times;

ll q_exp(ll a, ll k, ll mod)
{
	if (!k) return 1;

	ll ans = 1;
	while (k)
	{
		if (k & 1) ans = ans * a % mod;
		a = a * a % mod;
		k >>= 1;
	}
	return ans;
}

ll q_mul(ll a, ll b, ll mod)
{
	if (!b) return 0;

	ll ans = 0;
	while (b)
	{
		if (b & 1) ans = (ans + a) % mod;
		a = (a + a) % mod;
		b >>= 1;
	}
	return ans;
}

ll random(ll n)
{
	return ((double)rand() / RAND_MAX * n + 0.5);
}

bool witness(ll a, ll n) //Check witness
{
	ll tem = n - 1;
	int j = 0;
	while (!(tem & 1))
	{
		tem /= 2;
		j++;
	}
	// n - 1 => a ^ r * s
	ll x = q_exp(a, tem, n);
	if (x == 1 || x == n - 1) return true;

	while (j--)
	{
		x = q_mul(x, x, n);
		if (x == n - 1) return true;
	}
	return false;
}

bool miller_rabin(ll p) //Generate random a to check if there is a witness of p.
{
	if (p == 2) return true;
	if (p < 2 || !(p & 1)) return false;

	for (int i = 1; i < TIMES; i++)
	{
		ll a = random(p - 2) + 1;
		if (!witness(a, p))
		{
			return false;
		}
	}

	return true;
}

int main()
{
	ll n; cin>>n;

	if (miller_rabin(n))
	{
		puts("It's a prime.");
	}
	else
	{
		puts("It's not a prime.");
	}

	return 0;
}

```

## 质数判定 - 线性筛 .cpp

```cpp

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e7 + 5;

//notprime[n] == 0 means n is a prime.
//prim[0..top - 1] are primes below upLimit
int notprime[MAXN];
int prim[MAXN], top = 0;

void getPrime(int upLimit)
{
	notprime[0] = notprime[1] = 1;
	for (int i = 2; i <= upLimit; i++)
	{
		if (!notprime[i])
		{
			prim[top++] = i;
		}

		for (int j = 0; j < top; j++)
		{
			if (i * prim[j] > upLimit) break;

			notprime[i * prim[j]] = 1;

			if (i % prim[j] == 0) break;
		}
	}
	return ;
}

int main(int argc, char const *argv[])
{
	getPrime(200);
	cout<<"Top: "<<top<<endl;
	for (int i = 0; i < top; i++)
	{
		cout<<prim[i]<<" ";

		if (!(i % 10)) cout<<endl;
	}
	cout<<endl;
	return 0;
}

```

## 高精度 - BigInt.cpp

```cpp

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

	int d[MAXN], len = 0;
	
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

```

# 4.图论 - Graph

## 二分图最大匹配 - 匈牙利算法.cpp

```cpp

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e4 + 5;
int line[MAX][MAX];
int used[MAX], girl[MAX];
int all = 0;

bool find(int x)
{
    for (int j = 1; j<= m; j++)
    {
        if (line[x][y] == 1 %% used[j] == false)
        //如果有暧昧并且还没有标记过
        //这里标记的意思是这次查找曾试图改变过该妹子的归属问题，但是没有成功，所以就不用瞎费工夫了
        {
            used[j] = 1;
            if (girl[j] == 0 || find(girl[j]))
            //名花无主或者能腾出个位置来，这里使用递归  
            {
                girl[j] = x;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    for (int i = 1; i <= n; i++)
    {
        memset(used, 0, sizeof(used));//每次清空
        if (find(i)) all += 1;
    }
    return 0;
}
```

## 单源最短路 - Dijkstra堆优化.cpp

```cpp

/*
 * Dijkstra适用于: 正权连通图
 */

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1E5 + 5;
const int MAXM = 5E5 + 5;

struct Node
{
	Node(){}
	Node(int d, int p)
	{
		this->dis = d; this->pos = p;
	}

	int dis, pos;

	bool operator>(const Node &other) const
	{
		return this->dis > other.dis;
	}
};

struct Edge
{
	int to, cost, next;

	Edge(){}
	Edge(int t, int c, int n)
	{
		this->to = t;
		this->cost = c;
		this->next = n;
	}

}edge[MAXM];

int head[MAXN], dis[MAXN], cnt = 0;
bool vis[MAXN];

priority_queue<Node, vector<Node>, greater<Node> > q;

void dij(int s)
{
	memset(dis, 0x3f, sizeof(dis));
	dis[s] = 0;
	q.push(Node(0, s));

	while (!q.empty())
	{
		Node node = q.top(); q.pop();
		int u = node.pos;
		if (vis[u]) continue;
		
		vis[u] = 1;
		for (int i = head[u]; i; i = edge[i].next)
		{
			int v = edge[i].to;
			if (dis[v] > dis[u] + edge[i].cost)
			{
				dis[v] = dis[u] + edge[i].cost;
				if (!vis[v])
				{
					q.push(Node(dis[v], v));
				}
			}
		}
	}
}

inline void addEdge(int u, int v, int cost)
{
	cnt++;
	edge[cnt] = Edge(v, cost, head[u]);
	head[u] = cnt;
}


int n, m, s;

int main()
{
	scanf("%d%d%d", &n, &m, &s);
	for (int i = 0; i < m; i++)
	{
		int u, v, cost;
		scanf("%d%d%d", &u, &v, &cost);
		addEdge(u, v, cost);
		//addEdge(v, u, cost); //<-无向图
	}
	dij(s);

	for (int i = 1; i <= n; i++)
	{
		printf("%d ", (dis[i] != 0x3f3f3f3f? dis[i]: 2147483647));
	}

	return 0;
}

```

## 单源最短路 - SPFA.cpp

```cpp

/*
 * SPFA 也适用于负权图
 * SPFA的时间复杂度O(N*M)=O(V*E)要大于堆优化的O((N + M) * logN)
 * 所以在正权图中最好使用堆优化Dij(1e5已经跑不动了)
 */

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 5;
const int MAXM = 5e5 + 5;

struct Edge
{
	Edge(){}
	Edge(int t, int c)
	{
		this->to = t; this->cost = c;
	}

	int to, cost;
}temp;
queue<int> q;
vector<Edge> edge[MAXN];
int dis[MAXN], vis[MAXN];

void spfa(int s)
{
	memset(dis, 0x3f, sizeof(dis));

	vis[s] = 1; dis[s] = 0;
	q.push(s);

	while (!q.empty())
	{
		int u = q.front();
		for (int i = 0; i < edge[u].size(); i++)
		{
			int v = edge[u][i].to;
			int cost = edge[u][i].cost;
			if (dis[v] > dis[u] + cost)
			{
				dis[v] = dis[u] + cost;

				if (!vis[v])
				{
					vis[v] = 1;
					q.push(v);
				}
			}
		}
		q.pop();
		vis[u] = 0;
	}
}

int n, m, s;

int main()
{
	scanf("%d%d%d", &n, &m, &s);
	for (int i = 0; i < m; i++)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		edge[u].push_back(Edge(v, w));
		//edge[v].push_back(Edge(u, w)); //<-无向图
	}

	spfa(s);

	for (int i = 1; i <= n; i++)
	{
		printf("%d ", (dis[i] != 0x3f3f3f3f? dis[i]: 0x7fffFFFF));
	}
	printf("\n");

	return 0;
}

```

## 最小生成树MST - Kruskal.cpp

```cpp

#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e5 + 5;
const int MXN = 5e3 + 5;
struct Edge
{
	int p1, p2, cost;
	
	bool operator<(const Edge &other) const
	{
		return (*this).cost < other.cost;
	}
	
	Edge(int P1 = 0, int P2 = 0, int C = 0):p1(P1), p2(P2), cost(C){}
}edge[MAX];
int father[MXN];
int mst = 0,  cnt = 0;
int n, m;

int getf(int p)
{
	if (father[p] != p)
	{
		father[p] = getf(father[p]);
	}
	return father[p];
}

inline void unite(int a, int b)
{
	father[getf(a)] = getf(b);
	return ;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &edge[i].p1, &edge[i].p2, &edge[i].cost);
	}
	for (int i = 1; i <= n; i++)
	{
		father[i] = i;
	}
	
	sort(edge + 1, edge + 1 + m);
	cnt = n;
	
	for (int i = 1; i <= m; i++)
	{
		if (!n) break;
		
		int u = edge[i].p1;
		int v = edge[i].p2;

		if (getf(u) != getf(v))
		{
			unite(u, v);
			mst += edge[i].cost;
			cnt--;
		}
	}
	
	if (cnt != 1)
	{
		printf("orz\n");
	}
	else
	{
		printf("%d\n", mst);
	}
	
	return 0;
}
```

# 5.数据结构 - Stucture

## 并查集.cpp

```cpp

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
int father[MAXN];

int getf(int p)
{
	if (father[p] != p)
	{
		father[p] = getf(father[p]);
	}
	return father[p];
}

void unite(int a, int b)
{
	if (getf(a) != getf(b))
	{
		father[getf(a)] = getf(b);
	}
}

void initf(int maxn)
{
	for (int i = 1; i <= maxn; i++)
	{
		father[i] = i;
	}
}


int n, m;
int z, x, y;

int main()
{
	scanf("%d%d", &n, &m);
	initf(n);

	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &z, &x, &y);
		if (z == 1)
		{
			unite(x, y);
		}
		else
		{
			printf("%c\n", (getf(x) != getf(y))? 'N': 'Y');
		}
	}

	return 0;
}

```

## 树状数组 - 区间修改单位求值.cpp

```cpp

/*
 * add(p, delta) 表示将从p到n的所有数的变化量增加delta
 * sum(p) 返回a[p]的 >变化量<
 */

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 50;
int a[MAXN], c[MAXN], n = 0;

inline int lowbit(int i)
{
	return i & (-i);
}

void add(int p, int delta)
{
	for (; p <= n; p += lowbit(p))
	{
		c[p] += delta;
	}
}

int sum(int p)
{
	int ans = 0;
	for (; p > 0; p -= lowbit(p))
	{
		ans += c[p];
	}
	return ans;
}

int m = 0;
int opt, x, y, k;

int main()
{
	cin>>n>>m;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int t = 1; t <= m; t++)
	{
		cin>>opt;
		switch (opt)
		{
			case 1:
				{
					cin>>x>>y>>k;
					add(x, k);
					add(y + 1, -k);
					break;
				}
			case 2:
				{
					cin>>x;
					printf("%d\n", a[x] + sum(x));
					break;
				}
		}
	}
	return 0;
}

```

## 树状数组 - 单位修改区间求和.cpp

```cpp

/*
 * add(p, delta) 表示将点p增加delta
 * sum(p) 表示从p到n的和
 */

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500000 + 5;
int c[MAXN], a[MAXN], n = 0;

inline int lowbit(int p)
{
	return p & (-p);
}

void add(int p, int delta)
{
	a[p] += delta;
	for (; p <= n; p += lowbit(p))
	{
		c[p] += delta;
	}
}

int sum(int p)
{
	int ans = 0;
	for (; p > 0; p -= lowbit(p))
	{
		ans += c[p];
	}
	return ans;
}

int m, opt, x, y, tmp;

int main()
{
	cin>>n>>m;
	for (int i = 1; i <= n; i++)
	{
		cin>>tmp;
		add(i, tmp);
	}
	
	for (int t = 0; t < m; t++)
	{
		cin>>opt>>x>>y;
		if (opt == 1)
		{
			add(x, y);
		}
		else
		{
			x == 1?
				cout<<sum(y)<<endl:
				cout<<sum(y) - sum(x-1)<<endl;
		}
	}
	
	return 0;
}

```

## 红黑树 - 基于STL.cpp

```cpp

/**
 * 基于pb_ds库中的tree, 可以通过extc++.h一键引用
 * 通过位移让红黑树可以插入重复的值
 */
#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> rbtree;

class Rb_Tree
{
private:
    
    const static int Offset = 20;
    rbtree _tr;
    int _ind = 1;

public:
    void add(ll x)
    {
        _tr.insert((x << Offset) + _ind);
        _ind++;
    }
    void del(ll x)
    {
        _tr.erase(_tr.lower_bound(x << Offset));
    }
    int rankof(ll x)
    {
        return _tr.order_of_key(x << Offset) + 1;
    }
    ll kth(int k)
    {
        return (*_tr.find_by_order(k - 1) >> Offset);
    }
    ll get_prev(ll x)
    {
        return (*--_tr.lower_bound(x << Offset) >> Offset);
    }
    ll get_next(ll x)
    {
        return (*_tr.lower_bound((x + 1) << Offset) >> Offset);
    }
};

Rb_Tree tr;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
    {
        ll opt, x; cin >> opt >> x;
        switch (opt)
        {
            case 1:
            {
                // Add
                tr.add(x);
            }
            break;
            case 2:
            {
                // Del
                tr.del(x);
            }
            break;
            case 3:
            {
                // Get rank
                cout << tr.rankof(x) << "\n";
            }
            break;
            case 4:
            {
                //Get kth
                cout << tr.kth(x) << "\n";
            }
            break;
            case 5:
            {
                // Get Prev
                cout << tr.get_prev(x) << "\n";
            }
            break;
            case 6:
            {
                // Get Next
                cout << tr.get_next(x) << "\n";
            }
            break;
            default: break;
        }
    }
    return 0;
}```

## 线段树 - zkw线段树.cpp

```cpp

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;

// IO optimization
template <typename ty>
inline void read(ty &x)
{
	x = 0; int w = 0; char ch = getchar();
	while (!isdigit(ch))
	{
		w |= ch == '-'; ch = getchar();
	}
	while (isdigit(ch))
	{
		x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar();
	}
}

// Segment tree main part
ll st[MAXN << 2], add[MAXN << 2];
int n, N = 1;

inline void build()
{
	for (; N < n + 1; N <<= 1); // Get raw data's place.
	for (int i = N + 1; i <= N + n; i++) read(st[i]); // Raw data.
	for (int i = N - 1; i >= 1; i--) st[i] = st[i << 1] + st[i << 1 | 1]; // Build from leaves.
}

inline void update(int l, int r, ll k)
{
	int s = N + l - 1, t = N + r + 1; // Left and Right.
	ll lNum = 0, rNum = 0, num = 1; // how many k left contained = lNum, how many k this plate contained = num.
	for (; s ^ t ^ 1; s >>= 1, t >>= 1, num <<= 1) // If s and t has same father, s ^ t == 1, 1 ^ 1 == 0
	{
		st[s] += k * lNum;
		st[t] += k * rNum;
		if (~s & 1) {add[s ^ 1] += k; st[s ^ 1] += k * num; lNum += num;} // If s is the left kid of its father, add its brother node.
		if ( t & 1) {add[t ^ 1] += k; st[t ^ 1] += k * num; rNum += num;} // If t is the right kid of its father, add its brother node.
	}
	for (; s; s >>= 1, t >>= 1) // Up to root
	{
		st[s] += k * lNum;
		st[t] += k * rNum;
	}
}

inline ll query(int l, int r)
{
	int s = N + l - 1, t = N + r + 1; // Left and Right.
	ll lNum = 0, rNum = 0, num = 1, ans = 0; // Same as update()#lNum.
	for (; s ^ t ^ 1; s >>= 1, t >>= 1, num <<= 1)
	{
		if (add[s]) ans += add[s] * lNum; // Add the add lazy tag.
		if (add[t]) ans += add[t] * rNum;
		if (~s & 1) {ans += st[s ^ 1]; lNum += num;}
		if ( t & 1) {ans += st[t ^ 1]; rNum += num;}
	}
	for (; s; s >>= 1, t >>= 1) // Up to root
	{
		ans += add[s] * lNum;
		ans += add[t] * rNum;
	}
	return ans;
}

// For luogu p3372
int main(int argc, char const *argv[])
{
	int m; read(n); read(m);
	build();

	for (int i = 0; i < m; i++)
	{
		int opt; read(opt);
		switch (opt)
		{
			case 1:
			{
				int x, y, k; read(x); read(y); read(k);
				update(x, y, k);
				break;
			}
			case 2:
			{
				int x, y; read(x); read(y);
				printf("%lld\n", query(x, y));
				break;
			}
		}
	}

	return 0;
}
```

## 线段树 - 递归线段树.cpp

```cpp

//Luogu p3373
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;
class SegmentTree
{
public:
    SegmentTree(){}

    int l, r;
    ll data, add_tag = 0, mul_tag = 1;
} st[4 * MAXN + 2];
int n, m, mod;
ll raw_data[MAXN];

inline int lson(int p){return p << 1;}
inline int rson(int p){return p << 1 | 1;}

void push_up(int p)
{
    st[p].data = (st[lson(p)].data + st[rson(p)].data) % mod;
}

void build(int p, int l, int r)
{
    st[p].l = l; st[p].r = r;

    if (l == r)
    {
        st[p].data = raw_data[l];
        return ;
    }

    int mid = (l + r) >> 1;
    build(lson(p), l, mid);
    build(rson(p), mid + 1, r);

    push_up(p);
}

void lazy_down(int p)
{
    if (st[p].add_tag || st[p].mul_tag != 1)
    {
        st[lson(p)].data = st[lson(p)].data * st[p].mul_tag % mod;
        st[lson(p)].mul_tag = st[lson(p)].mul_tag * st[p].mul_tag % mod;
        st[lson(p)].add_tag = st[lson(p)].add_tag * st[p].mul_tag % mod;

        st[rson(p)].data = st[rson(p)].data * st[p].mul_tag % mod;
        st[rson(p)].mul_tag = st[rson(p)].mul_tag * st[p].mul_tag % mod;
        st[rson(p)].add_tag = st[rson(p)].add_tag * st[p].mul_tag % mod;

        st[p].mul_tag = 1;

        st[lson(p)].add_tag +=st[p].add_tag;
        st[lson(p)].data += st[p].add_tag * (st[lson(p)].r - st[lson(p)].l + 1);
        st[rson(p)].add_tag +=st[p].add_tag;
        st[rson(p)].data += st[p].add_tag * (st[rson(p)].r - st[rson(p)].l + 1);

        st[p].add_tag = 0;
    }
}

void add(int p, int l, int r, ll k)
{
    if (st[p].l >= l && st[p].r <= r)
    {
        st[p].data = (st[p].data + k * (st[p].r - st[p].l + 1)) % mod;
        st[p].add_tag += k;
        return ;
    }

    lazy_down(p);

    int mid = (st[p].l + st[p].r) >> 1;
    if (mid >= l) add(lson(p), l, r, k);
    if (mid <  r) add(rson(p), l, r, k);

    push_up(p);
}

void mul(int p, int l, int r, ll k)
{
    if (st[p].l >= l && st[p].r <= r)
    {
        st[p].data = st[p].data * k % mod;
        st[p].mul_tag = st[p].mul_tag * k % mod;
        st[p].add_tag = st[p].add_tag * k % mod;
        return ;
    }

    lazy_down(p);

    int mid = (st[p].l + st[p].r) >> 1;
    if (mid >= l) mul(lson(p), l, r, k);
    if (mid <  r) mul(rson(p), l, r, k);

    push_up(p);
}

long long query(int p, int l, int r)
{
    if (st[p].l >= l && st[p].r <= r) return st[p].data % mod;

    lazy_down(p);

    ll ans = 0;
    int mid = (st[p].l + st[p].r) >> 1;
    if (mid >= l) ans += query(lson(p), l, r);
    if (mid <  r) ans += query(rson(p), l, r);

    return ans;
}

int main(int argc, char const *argv[])
{

    scanf("%d%d%d", &n, &m, &mod);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &raw_data[i]);
    }
    build(1, 1, n);

    for (int i = 0; i < m; i++)
    {
        int cmd;
        scanf("%d", &cmd);
        switch (cmd)
        {
            case 1:
            {
                int x, y, k;
                scanf("%d%d%d", &x, &y, &k);
                mul(1, x ,y, k);
                break;
            }
            case 2:
            {
                int x, y, k;
                scanf("%d%d%d", &x, &y, &k);
                add(1, x, y, k);
                break;
            }
            case 3:
            {
                int x, y;
                scanf("%d%d", &x, &y);
                printf("%lld\n", query(1, x, y) % mod);
                break;
            }
        }
    }
    
    return 0;
}
```

# 6.动态规划 - Dynamic Programming

## 0.常见DP.cpp

```cpp

/*
   描述状态的参数大多数可分为：
   		描述位置的
		描述数量的
		描述对之后状态的影响的
		etc.
*/

/*
	1.线性DP
		最长不下降子序列
		最大子序列和
		最长公共子序列
		背包问题
		etc.

	2.区间DP
		括号匹配问题
		etc.

	3.多线程DP
		传纸条问题
		etc.

	4.树形DP
		树的最小点覆盖问题
		etc.
	
	5.状态压缩DP等各种优化（如位运算）
		etc.
*/

```

## 1. 01背包.cpp

```cpp

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
```

## 2. 完全背包.cpp

```cpp

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

```

## 3. 多重背包.cpp

```cpp

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

```

