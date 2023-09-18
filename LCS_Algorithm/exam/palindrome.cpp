#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        string s;
        cin >> s;

        int n = s.size();
        string str2 = s;

        reverse(str2.begin(), str2.end());
        int m = str2.size();

        int dp[n + 1][m + 1];

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == str2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        cout << s.size() - dp[n][m] << endl;
    }

    return 0;
}
