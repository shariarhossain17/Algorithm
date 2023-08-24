#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1e5 + 10;
const int infinity = 1e9 + 10;

vector<pii> adj[N];
vector<int> dist(N, infinity);
vector<bool> visited(N, false);

void dijkstra(int src)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[src] = 0;

    pq.push({dist[src], src}); // 0,1

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        visited[u] = true;

        for (pii vpair : adj[u])
        {
            int v = vpair.second;
            int w = vpair.first;

            if (visited[v])
                continue;
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
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
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    int s, t;
    cin >> s >> t;

    dijkstra(s);

    cout << dist[t];

    return 0;
}