#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
int visited[N];
void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        cout << front << " ";

        for (int v : adj[front])
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

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        // adj[v].push_back(u);
    }

    bfs(1);

    // for (int i = 1; i <= n; i++)
    // {

    //     cout << "list " << i << ": ";
    //     for (int v : adj[i])
    //     {
    //         cout << v << " ";
    //     }

    //     cout << endl;
    // }

    return 0;
}