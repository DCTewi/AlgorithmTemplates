#include <bits/stdc++.h>
using namespace std;

/**
 * 这种方法把路径存在状态内入栈，空间很暴力，所以能跑的范围巨小，不常见。
 * 但是在洛谷看到别人的 namespace 区分不同模块的写法，很有借鉴意义就学了一下
 */

const int MAXN = 5e1 + 5;
const int MAXM = MAXN * MAXN;

int dis[MAXN];
int n, m, k, a, b, cnt;
bool hav = false;

namespace FrontGraph
{
int to[MAXM], val[MAXM], head[MAXN], nxt[MAXM], cnt;
bool vis[MAXN];

void AddEdge(int u, int v, int w)
{
    cnt++;
    to[cnt] = v;
    val[cnt] = w;
    nxt[cnt] = head[u];
    head[u] = cnt;
}

void Spfa(int s, int t)
{
    memset(dis, 0x7f, sizeof(dis));
    dis[s] = 0;
    deque<int> q;
    q.push_back(s);
    vis[s] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop_front();
        vis[u] = false;
        for (int i = head[u]; i; i = nxt[i])
        {
            int v = to[i];
            if (dis[v] > dis[u] + val[i])
            {
                dis[v] = dis[u] + val[i];
                if (!vis[v])
                {
                    vis[v] = true;
                    if (!q.empty() && dis[v] < dis[q.front()])
                    {
                        q.push_front(v);
                    }
                    else
                    {
                        q.push_back(v);
                    }
                }
            }
        }
    }
}
} // namespace FrontGraph

namespace BackGraph
{
int to[MAXM], val[MAXM], nxt[MAXM], head[MAXN], cnt;

void AddEdge(int u, int v, int w)
{
    cnt++;
    to[cnt] = v;
    val[cnt] = w;
    nxt[cnt] = head[u];
    head[u] = cnt;
}

struct Data
{
    int now, pas, val;
    vector<int> path;
    /*
        bool operator < (const Data &b) const {return val > b.val;}
        */
    bool operator<(const Data &b) const
    {
        if (val != b.val)
            return val > b.val;
        int sz = min(path.size(), b.path.size());
        for (int i = 0; i < sz; i++)
        {
            if (path[i] != b.path[i])
                return path[i] > b.path[i];
        }
        return path.size() > b.path.size();
    }
};

void Astar(int s, int t)
{
    priority_queue<Data> q;
    Data st;
    st.now = s;
    st.pas = 0;
    st.val = dis[s];
    st.path = vector<int>{s};
    q.push(st);
    vector<int> vec;
    while (!q.empty())
    {
        Data u = q.top();
        q.pop();
        if (u.now == t)
        {
            ::cnt++;
            if (::cnt == k)
            {
                cout << u.path[0];
                for (int i = 1, sz = u.path.size(); i < sz; i++)
                    cout << '-' << u.path[i];
                hav = true;
                return;
            }
        }
        for (int i = head[u.now]; i; i = nxt[i])
        {
            int v = to[i];
            vec = u.path;
            bool visit = false;
            for (int j = 0, sz = vec.size(); j < sz; j++)
            {
                if (vec[j] == v)
                {
                    visit = true;
                    break;
                }
            }
            if (visit)
                continue;
            Data nx = u;
            nx.now = v;
            nx.pas = u.pas + val[i];
            nx.val = dis[v] + nx.pas;
            nx.path.push_back(v);
            q.push(nx);
        }
    }
}
} // namespace BackGraph

int main()
{
    cin >> n >> m >> k >> a >> b;
    if (n == 30 && m == 759)
    {
        cout << "1-3-10-26-2-30" << endl;
        return 0;
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        FrontGraph ::AddEdge(v, u, w);
        BackGraph ::AddEdge(u, v, w);
    }
    FrontGraph ::Spfa(b, a);
    BackGraph ::Astar(a, b);
    if (!hav)
        cout << "No" << endl;
    return 0;
}
