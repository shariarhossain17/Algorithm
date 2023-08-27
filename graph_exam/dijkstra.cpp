#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int INF = 1e9 + 10;

typedef pair<int, int> pii;

vector<pii> g[N];

vector<long long int> dist(N, INF);
vector<int> visited(N, false);

void dijkstra(int src, int d, int dw)
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
            }
        }
    }

    if (dist[d] <= dw)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}
int main()
{

    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({w, v});
    }

    int src;
    cin >> src;

    int t;
    cin >> t;
    while (t--)
    {

        int d, dw;
        cin >> d >> dw;
        dijkstra(src, d, dw);
    }
    return 0;
}