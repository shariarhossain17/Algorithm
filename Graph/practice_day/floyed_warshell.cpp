#include <bits/stdc++.h>
using namespace std;
const int INF = 1e7 + 5;
int main()
{

    int n;
    cin >> n;
    int ar[n + 1][n + 1];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> ar[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (ar[i][j] == -1)
                ar[i][j] = INT_MAX / 2;
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (ar[i][j] > ar[i][k] + ar[k][j])
                {
                    ar[i][j] = ar[i][k] + ar[k][j];
                }
            }
        }
    }

    int mx = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            if (ar[i][j] == INT_MAX / 2)
                continue;
            if (ar[i][j] > mx)
            {
                mx = ar[i][j];
            }
        }
    }

    cout << mx;
    return 0;
}