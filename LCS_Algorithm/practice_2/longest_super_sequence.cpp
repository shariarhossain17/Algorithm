#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];
int lcs(string str1, int n, string str2, int m)
{
    if (n == 0 || m == 0)
        return 0;

    if (dp[n][m] != -1)
        return dp[n][m];
    if (str1[n - 1] == str2[m - 1])
    {
        return dp[n][m] = lcs(str1, n - 1, str2, m - 1) + 1;
    }
    else
    {
        return dp[n][m] = max(lcs(str1, n - 1, str2, m), lcs(str1, n, str2, m - 1));
    }
}
int main()
{

    string str1, str2;
    cin >> str1 >> str2;

    int n = str1.size();
    int m = str2.size();

    memset(dp, -1, sizeof(dp));
    cout << n + m - lcs(str1, n, str2, m);

    return 0;
}