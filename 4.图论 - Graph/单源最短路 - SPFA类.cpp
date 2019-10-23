#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e3 + 5;
const int MAXM = 5e5 + 5;

struct Edge
{
    int to;
    ll cost;
    int next;
    
    Edge(int t = 0, ll c = 0, int ne = 0)
    {
        to = t; cost = c; next = ne;
    }
};

struct Spfa
{
    vector<int> head;
    queue<int> q;
    vector<Edge> edges;
    ll dis[MAXN];
    int vis[MAXN];

    Spfa(int maxn)
    {
        head = vector<int>(maxn, 0);
        edges = vector<Edge>(1); // IMPORTANT // 
    }

    void addedge(int u, int v, ll w)
    {
        edges.emplace_back(Edge(v, w, head[u]));
        head[u] = edges.size() - 1;
    }

    ll run(int start, int fin)
    {
        memset(vis, 0, sizeof(vis));
        memset(dis, 0x3f, sizeof(dis));

        dis[start] = 0; vis[start] = 1; q.push(start);

        while (q.size())
        {
            int u = q.front();
            for (int i = head[u]; i; i = edges[i].next)
            {
                int v = edges[i].to, w = edges[i].cost;
                if (dis[v] > dis[u] + w)
                {
                    dis[v] = dis[u] + w;
                    if (!vis[v])
                    {
                        q.push(v); vis[v] = 1;
                    }
                }
            }
            q.pop(); vis[u] = 0;
        }
        
        return dis[fin];
    }
};