#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 3;
const int INF = 1e9 + 10;

int dist[N][N];

int n, m;

// step no 1 diagonal ke 0 kora and sob node gula infinite kora

void dist_initialize()
{

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i != j)
            {
                dist[i][j] = INF;
            }
        }
    }
};

void print_matrix()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dist[i][j] == INF)
                cout << "x"
                     << " ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{

    cin >> n >> m;

    dist_initialize();

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = w;
        dist[v][u] = w;
    }

    // d[i][j]=min{d[i,j],d[i,k]+d[k,j]}
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    print_matrix();
    return 0;
}