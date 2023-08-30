#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1e5 + 5;
const int INF = 1e9 + 10;

vector<pii> g[N];

vector<int> dist(N, INF);
vector<bool> visited(N);

int parent[N];

void dijkstra(int src)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[src] = 0;
    pq.push({dist[src], src});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        visited[u] = true;

        for (pii vpair : g[u])
        {
            int v = vpair.second;
            int w = vpair.first;

            if (visited[v])
                continue;
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
                parent[v] = u;
            }
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({w, v});
        g[v].push_back({w, u});
    }

    int src = 1, d = 5;
    dijkstra(1);

    int curr = d;

    while (curr != 0)
    {
        cout << curr;
        curr = parent[curr];
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << "parent" << i << ": ";

    //     cout << parent[i] << endl;
    // }
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << "distance of" << i << ": ";

    //     cout << dist[i] << endl;
    // }
    // input

    // for (int i = 1; i <= n; i++)
    // {

    //     cout << "list of" << i << ": ";
    //     for (pii v : g[i])
    //     {
    //         cout << "(" << v.first << " " << v.second << ") ";
    //     }

    //     cout << endl;
    // }
    return 0;
}