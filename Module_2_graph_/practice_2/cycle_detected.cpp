#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
int visited[N];

bool dfs(int u, int p = -1)
{
    bool exist = false;
    visited[u] = true;

    for (int v : adj[u])
    {
        if (v == p)
            continue;
        if (visited[v])
            return true;
        exist = exist || dfs(v, u);
    }

    return exist;
}
int main()
{

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (dfs(1))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}