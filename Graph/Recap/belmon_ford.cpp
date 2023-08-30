#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int N = 1e5 + 5;
vector<pii> g[N];

int dist[N];
int n, m;
void bellman_ford(int src)
{
    for (int i = 0; i < N; i++)
    {
        dist[i] = INT_MAX;
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

                if (dist[u] != INT_MAX && dist[u] + w < dist[v])
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

    for (int i = 1; i <= n; i++)
    {
        cout << "distance of" << i << ": " << dist[i] << endl;
    }

    return 0;
}