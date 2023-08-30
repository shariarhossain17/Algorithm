#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

vector<int> adj[N];

bool visited[1000];

void dfs(int u)
{

    visited[u] = true;

    for (int v : adj[u])
    {

        if (visited[v])
            continue;

        dfs(v);
    }
    cout << u << " ";
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
    return 0;
}