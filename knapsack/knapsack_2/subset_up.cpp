#include <bits/stdc++.h>
using namespace std;
int main()
{

    int n;
    cin >> n;
    int ar[n];

    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }

    int s;
    cin >> s;
    bool dp[n + 1][s + 1];
    dp[0][0] = true;
    for (int i = 1; i <= s; i++)
    {
        dp[0][i] = false;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= s; j++)
        {
            if (ar[i - 1] <= j)
            {
                bool opt1 = dp[i - 1][j - ar[i - 1]];
                bool opt2 = dp[i - 1][j];
                dp[i][j] = opt1 || opt2;
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    if (dp[n][s])
    {
        cout << "yes";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}