#include <bits/stdc++.h>
using namespace std;
#include <iostream>
using namespace std;

const int MAX_N = 1005;
const int MAX_M = 1005;

bool dp[MAX_N][MAX_M];

bool target_sum(int N, int M, int marks[])
{
    for (int i = 0; i <= N; i++)
    {
        dp[i][0] = true;
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (marks[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - marks[i - 1]];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[N][M];
}

int main()
{
    int T;
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        int N, M;
        cin >> N >> M;
        int marks[MAX_N];

        for (int i = 0; i < N; i++)
        {
            cin >> marks[i];
        }

        if (target_sum(N, 1000 - M, marks))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}
