#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

long long int maxWays(vector<int> &A, int N, int M)
{
    vector<int> dp(M + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < N; ++i)
    {
        for (int j = A[i]; j <= M; ++j)
        {
            dp[j] = (dp[j] + dp[j - A[i]]) % MOD;
        }
    }

    return dp[M];
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        long long int N, M;
        cin >> N >> M;

        vector<int> A(N);
        for (int i = 0; i < N; ++i)
        {
            cin >> A[i];
        }

        long long int ways = maxWays(A, N, 1000 - M);
        cout << ways << endl;
    }

    return 0;
}
