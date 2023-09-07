#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int dp[N][N];
int knapsack(int n, int s, int w[], int v[])
{
    if (n == 0 || s == 0)
        return 0;

    if (w[n - 1] <= s)
    {
        int choice1 = knapsack(n - 1, s - w[n - 1], w, v) + v[n - 1];
        int choice2 = knapsack(n - 1, s, w, v);

        return max(choice1, choice2);
    }

    else
        return knapsack(n - 1, s, w, v);
}

int main()
{
    int n, s;
    cin >> n >> s;
    int v[n], w[n];
    for (int i = 0; i < n; i++)
    {
        cin >> w[i] >> v[i];
    }
    cout << knapsack(n, s, w, v);
    return 0;
}