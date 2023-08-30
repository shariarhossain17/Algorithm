#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int ar[N][N];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        ar[u][v] = 1;
        ar[v][u] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << ar[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}