#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

vector<int> adj[N];

bool visited[1000];

int depth[N];

void dfs(int u)
{

    visited[u] = true;

    for (int v : adj[u])
    {
        if (visited[v])
            continue;

        depth[v] = depth[u] + 1;
        dfs(v);
    }
}
int main()
{

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int src = 1;
    dfs(1);

    int search;
    cin >> search;

    for (int i = 1; i <= n; i++)
    {
        if (i == search)
        {
            cout << "depth of " << i << ":" << depth[i];
        }
    }
    return 0;
}