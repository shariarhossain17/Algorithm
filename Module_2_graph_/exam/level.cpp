#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
bool visited[N];

int level[N];

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

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

    bfs(0);

    int target;
    cin >> target;
    vector<int> result;

    for (int i = 0; i <= N; i++)
    {

        if (level[i] == target)
        {
            result.push_back(i);
        }
    }
    sort(result.begin(), result.end());
    if (target == 0)
        cout << 0;
    else if (!result.empty())
    {
        for (int v : result)
        {
            cout << v << " ";
        }
    }
    else
        cout << -1;

    return 0;
}
