#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1e5 + 5;
const int INF = 1e7;
vector<pii> g[N];

int dist[N];

int n, m;
void bellman_ford(int src)
{
    for (int i = 0; i < N; i++)
    {
        dist[i] = INF;
    }

    dist[src] = 0;

    for (int i = 1; i < n; i++)
    {
        for (int u = 1; u <= n; u++)
        {
            for (pii vpair : g[u])
            {
                int v = vpair.second;
                int w = vpair.first;

                if (dist[u] < INF && dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                }
            }
        }
    }
}
int main()
{

    cin >> n >> m;

    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({w, v});
    }

    bellman_ford(1);

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << "list of" << i << ": ";
    //     for (pii vapair : g[i])
    //     {
    //         cout << "(" << vapair.second << " " << vapair.first << ")";
    //     }

    //     cout << endl;
    // }

    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == INF)
            cout << 30000 << " ";
        else
            cout << dist[i] << " ";
    }

    return 0;
}