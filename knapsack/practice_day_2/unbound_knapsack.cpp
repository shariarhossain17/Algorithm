#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];
int unbound_knapsack(int N, int W, int val[], int wt[])
{

    // base case
    if (N == 0 || W == 0)
        return 0;

    if (dp[N][W] != -1)
        return dp[N][W];

    if (wt[N - 1] <= W)
    {
        int ch1 = unbound_knapsack(N, W - wt[N - 1], val, wt) + val[N - 1];
        int ch2 = unbound_knapsack(N - 1, W, val, wt);
        return dp[N][W] = max(ch1, ch2);
    }
    else
    {
        return dp[N][W] = unbound_knapsack(N - 1, W, val, wt);
    }
}
int main()
{
    int N, W;
    cin >> N >> W;

    int val[N], wt[N];

    for (int i = 0; i < N; i++)
    {
        cin >> val[i];
    }
    for (int i = 0; i < N; i++)
    {
        }
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            dp[i][j] = -1;
        }
    }
    cout << unbound_knapsack(N, W, val, wt);
    return 0;
}