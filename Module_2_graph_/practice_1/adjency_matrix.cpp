#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 3;

int adj[N][N];
int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> adj[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << "List" << i << ": ";
        bool first = true;
        for (int j = 1; j <= n; j++)
        {
            if (adj[i][j] == 1)
            {
                if (!first)
                    cout << " ";
                cout << j;
                first = false;
            }
        }
        cout << endl;
    }
    return 0;
}