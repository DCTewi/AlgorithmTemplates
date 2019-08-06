#include <bits/stdc++.h>
using namespace std;

/*
    // Chinese++:
    void tarjan(当前点 u)
    {
        初始化low, dfn
        将点入栈并标记
        枚举所有相连边 另一端点 v
        {
            如果v为标记dfn
            {
                tarjan(v);
                更新low[u]
            }
            如果v在栈内 == v更low
            {
                更新low[u]
            }
        }
        如果low[u] == dfn[u]
        {
            从栈顶到该点为一个强联通分量
        }
    }
 */

const int MAXN = 5e3 + 5;
const int MAXM = 5e4 + 5;

// 链式前向星
struct Edge
{
    int to, next, cost;
} edge[MAXM << 2];
int head[MAXN];
void add_edge(int u, int v, int w)
{
    static int cnt = 0;
    cnt++;
    edge[cnt].to = v;
    edge[cnt].cost = w;
    edge[cnt].next = head[u];
    head[u] = cnt;
}

// 正文
int low[MAXN], dfn[MAXN], vis[MAXN], ind = 0;
stack<int> q;
void tarjan(int u)
{
    low[u] = dfn[u] = ++ind;
    q.push(u); vis[u] = 1;
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (vis[v])
        {
            low[u] = min(low[u], low[v]);
        }
    }
    if (low[u] == dfn[u])
    {
        // 此时得到强联通分量，可进行相关操作
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        add_edge(u, v, w);
    }

    // 对整个图求强联通分量
    for (int i = 1; i <= n; i++)
    {
        if (!dfn[i]) tarjan(i);
    }

    return 0;
}
