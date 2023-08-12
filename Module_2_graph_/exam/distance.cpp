#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> adj[N];
bool visited[N];

int level[N];

int bfs(int s, int d)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        if (u == d)
            return level[d];

        for (int v : adj[u])
        {
            if (!visited[v])
            {
                q.push(v);
                visited[v] = true;
                level[v] = level[u] + 1;
            }
        }
    }
    return -1;
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

    int q;
    cin >> q;
    int s, d;

    while (q--)
    {
        cin >> s >> d;
        fill(visited, visited + N, false);
        fill(level, level + N, 0);

        int distance = bfs(s, d);
        cout << distance << endl;
    }

    return 0;
}
