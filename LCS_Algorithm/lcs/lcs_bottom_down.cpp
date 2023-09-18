#include <bits/stdc++.h>
using namespace std;

int lcs_bottom_down(string a, int n, string b, int m)
{
    // base case
    if (n == 0 || m == 0)
        return 0;

    if (a[n - 1] == b[m - 1])
    {
        int ans = lcs_bottom_down(a, n - 1, b, m - 1);
        return ans + 1;
    }
    else
    {
        int ans1 = lcs_bottom_down(a, n - 1, b, m);
        int ans2 = lcs_bottom_down(a, n, b, m - 1);

        return max(ans1, ans2);
    }
}
int main()
{

    string a, b;
    cin >> a >> b;

    cout << lcs_bottom_down(a, a.size(), b, b.size());
    return 0;
}