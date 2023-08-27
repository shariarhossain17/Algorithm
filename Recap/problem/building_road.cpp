#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector<int> g[N];

vector<bool> visited(N, false);

void dfs(int u)
{
    visited[u] = true;

    for (int v : g[u])
    {
        if (visited[v])
            continue;
        visited[v] = true;
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

    vector<int> building;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
            continue;
        dfs(i);
        building.push_back(i);
    }

    cout << building.size() - 1 << endl;
    for (int i = 0; i < building.size() - 1; i++)
    {
        cout << building[i] << " " << building[i + 1] << endl;
    }
    return 0;
}