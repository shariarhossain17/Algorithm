#include <bits/stdc++.h>
using namespace std;

const int N = 105; // Adjust this based on the maximum value of N
const long long INF = LLONG_MAX;

long long mat[N][N];

int main()
{
    int n, e;
    cin >> n >> e;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            mat[i][j] = INF;
        }
        mat[i][i] = 0;
    }

    for (int i = 0; i < e; i++)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        mat[u][v] = min(mat[u][v], w);
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (mat[i][k] != INF && mat[k][j] != INF)
                {
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                }
            }
        }
    }

    int q;
    cin >> q;

    while (q--)
    {
        int s, d;
        cin >> s >> d;

        if (mat[s][d] == INF)
            cout << -1 << "\n";
        else
            cout << mat[s][d] << "\n";
    }

    return 0;
}
