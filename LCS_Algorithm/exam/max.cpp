#include <bits/stdc++.h>
using namespace std;

long long maxWays(int n, int m, vector<int> &marks)
{
    // Create a DP table to store the maximum number of ways to obtain a perfect score of 1000, starting from each possible mark in the list.
    long long dp[n + 1][1001];

    // Initialize the DP table.
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= 1000; j++)
        {
            dp[i][j] = 0;
        }
    }

    // Set the base case.
    dp[0][0] = 1;

    // Iterate over the DP table, starting from the first mark in the list.
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= 1000; j++)
        {
            // If we can add the current mark to the current mark in the DP table to obtain a sum that is less than or equal to 1000, then we update the DP table entry for that sum with the maximum number of ways to obtain that sum, which is the current number of ways plus the number of ways to obtain a perfect score of 1000, starting from the current mark minus the current mark.
            if (j + marks[i - 1] <= 1000)
            {
                dp[i][j + marks[i - 1]] = (dp[i][j + marks[i - 1]] + dp[i - 1][j]) % 1000000007;
            }
        }
    }

    // Return the maximum number of ways to obtain a perfect score of 1000, starting from the current mark.
    return (m <= 1000 && dp[n][m] > 0 && dp[n][m] < 1000000007) ? dp[n][m] : 0;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<int> marks(n);
        for (int i = 0; i < n; i++)
        {
            cin >> marks[i];
        }

        long long max_ways = maxWays(n, 1000 - m, marks);

        cout << max_ways << endl;
    }

    return 0;
}