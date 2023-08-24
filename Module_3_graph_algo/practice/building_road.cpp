#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

vector<int> adj[N];
vector<bool> visited(N, false);

void print_list(int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << "list of" << i << ": ";
        for (int v : adj[i])
        {
            cout << v << " ";
        }
        cout << endl;
    }
}

void dfs(int u)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (visited[v])
            continue;
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

    vector<int> parent;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
            continue;
        parent.push_back(i);
        dfs(i);
    }

    cout << parent.size() - 1 << endl;

    for (int v : parent)
    {
        cout << v << " ";
    }
    return 0;
}