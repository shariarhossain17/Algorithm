#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1e5 + 5;
const int INF = 1e9 + 7;

vector<pii> adj[N];

int dist[N];

int n, m;
void bellman_ford(int src)
{
    for (int i = 1; i <= n; i++)
        dist[i] = INF;
    dist[src] = 0;
    for (int i = 1; i < n; i++)
    {
        for (int u = 1; u <= n; u++)
        {
            for (pii vapir : adj[u])
            {
                int v = vapir.second;
                int w = vapir.first;
                if (dist[u] != INF && dist[u] + w < dist[v])
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
        adj[u].push_back({w, v});
    }

    bellman_ford(1);

    for (int i = 1; i <= n; i++)
    {
        cout << "distance" << i << ": " << dist[i] << endl;
    }

    return 0;
}