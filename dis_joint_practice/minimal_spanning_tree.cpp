#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
typedef pair<int, int> pii;

vector<pii> g[N];

vector<bool> visited(N, false);

class Edges
{
public:
    int a;
    int b;
    int c;

    Edges(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

class cmp
{
public:
    bool operator()(Edges a, Edges b)
    {
        return a.c > b.c;
    }
};
void minimal_spanning_tree(int src)
{

    priority_queue<Edges, vector<Edges>, cmp> pq;

    pq.push({src, src, 0});  // 1  1 0
    vector<Edges> edgesList; // 1 1 0

    while (!pq.empty())
    {
        Edges parent = pq.top();
        pq.pop();

        int u = parent.a; // 1
        int v = parent.b; // 1
        int w = parent.c; // 0

        if (visited[v])
            continue;
        visited[v] = true;
        edgesList.push_back({u, v, w});

        for (pii vpair : g[v])
        {
            int children = vpair.first;
            int weight = vpair.second;
            if (visited[children])
                continue;
            pq.push({u, children, weight});
        }
    }

    long long int sum = 0;
    for (Edges i : edgesList)
    {
        sum += i.c;
    }

    cout << sum;
};
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

    minimal_spanning_tree(1);

    // for (int i = 1; i <= n; i++)
    // {
    //     for (pii vpair : g[i])
    //     {
    //         cout << vpair.first << vpair.second;
    //     }

    //     cout << endl;
    // }

    return 0;
}