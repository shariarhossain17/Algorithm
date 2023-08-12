#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];

int visited[N];

vector<int> v;
void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        v.push_back(u);
        for (int v : adj[u])
        {
            if (visited[v])
                continue;
            q.push(v);
            visited[v] = true;
        }
    }
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

    bfs(1);

    reverse(v.begin(), v.end());
    for (int i : v)
    {
        cout << i << " ";
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << "list" << i << ": ";
    //     for (int v : adj[i])
    //     {
    //         cout << v << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}