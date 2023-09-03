#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
const long long INF = LLONG_MAX;

class Edge
{
public:
    int u, v;
    long long w;

    Edge(int u, int v, long long w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

vector<Edge> edges;
long long dist[N];
int n, e;

void bellmanFord(int source)
{
    fill(dist, dist + N, INF);
    dist[source] = 0;

    for (int i = 1; i <= n - 1; i++)
    {
        for (const Edge &edge : edges)
        {
            if (dist[edge.u] != INF && dist[edge.u] + edge.w < dist[edge.v])
            {
                dist[edge.v] = dist[edge.u] + edge.w;
            }
        }
    }

    for (const Edge &edge : edges)
    {
        if (dist[edge.u] != INF && dist[edge.u] + edge.w < dist[edge.v])
        {
            cout << "Negative Cycle Detected\n";
            exit(0);
        }
    }
}

int main()
{
    cin >> n >> e;

    for (int i = 0; i < e; i++)
    {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        edges.push_back(Edge(a, b, w));
    }

    int source;
    cin >> source;

    bellmanFord(source);

    int t;
    cin >> t;
    while (t--)
    {
        int destination;
        cin >> destination;

        if (dist[destination] == INF)
            cout << "Not Possible\n";
        else
            cout << dist[destination] << "\n";
    }

    return 0;
}
