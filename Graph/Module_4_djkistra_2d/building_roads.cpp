#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

vector<bool> visited(N, false);
vector<int> g[N];

void dfs(int u)
{
    visited[u] = true;

    for (int v : g[u])
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
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> v;

    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
            continue;

        v.push_back(i);
        dfs(i);
    }

    cout << v.size() - 1 << endl;

    for (int i = 1; i < v.size(); i++)
    {
        cout << v[i - 1] << " " << v[i];
    }

    return 0;
}