#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> g[N];

vector<bool> visited(N, false);

int level[N];

int parent[N];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;
    level[src] = 0;
    parent[src] = -1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        // cout << u << " ";

        for (int v : g[u])
        {
            if (visited[v])
                continue;
            q.push(v);
            visited[v] = true;
            level[v] = level[u] + 1;
            parent[v] = u;
        }
    }
}
int main()
{

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    bfs(1);

    // vector<int> path;
    // int curr = 4;

    // while (curr != -1)
    // {
    //     path.push_back(curr);
    //     curr = parent[curr];
    // }

    // for (int node : path)
    // {
    //     cout << node << " ";
    // }

    // level
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << "level of" << i << ": " << level[i] << endl;
    // }

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << "list " << i << ": ";

    //     for (int v : g[i])
    //     {
    //         cout << v << " ";
    //     }

    //     cout << endl;
    // }
    return 0;
}