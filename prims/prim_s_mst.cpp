#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1e5 + 5;
vector<pii> g[N];

vector<bool> visited(N, false);
class Edges
{
public:
    int u;
    int v;
    int w;

    Edges(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

class cmp
{
public:
    bool operator()(Edges a, Edges b)
    {
        return a.w > b.w;
    }
};

void prims_mst(int src)
{
    priority_queue<Edges, vector<Edges>, cmp> pq;

    vector<Edges> edgeList;

    pq.push({src, src, 0});

    while (!pq.empty())
    {
        Edges parent = pq.top();
        pq.pop();

        int u = parent.u;
        int v = parent.v;
        int w = parent.w;

        if (visited[v])
            continue;
        visited[v] = true;
        edgeList.push_back({u, v, w});

        for (pii vpair : g[v])
        {
            int children = vpair.first;

            if (visited[children])
                continue;
            pq.push(Edges(v, children, vpair.second));
        }
    }

    for (Edges val : edgeList)
    {
        cout << val.u << " " << val.v << " " << val.w << endl;
    }
}
int main()
{

    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    prims_mst(1);
    return 0;
}