#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];
bool subset_sum(int n, int s, int ar[])
{
    if (n == 0)
    {
        if (s == 0)
            return true;
        else
            return false;
    }

    if (dp[n][s] != -1)
        return dp[n][s];

    if (ar[n - 1] <= s)
    {
        int opt1 = subset_sum(n - 1, s - ar[n - 1], ar);
        int opt2 = subset_sum(n - 1, s, ar);

        return dp[n][s] = opt1 || opt2;
    }

    else
        return dp[n][s] = subset_sum(n - 1, s, ar);
}
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
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            dp[i][j] = -1;
        }
    }

    if (subset_sum(n, s, ar))
        cout << "YES";
    else
        cout << "NO";

    return 0;
}