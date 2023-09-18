#include <bits/stdc++.h>
using namespace std;

int lcs(string text1, int n, string text2, int m)
{
    if (n == 0 || m == 0)
        return 0;

    if (text1[n - 1] == text2[m - 1])
    {
        int ch1 = lcs(text1, n - 1, text2, m - 1);
        return ch1 + 1;
    }
    else
    {
        int ch1 = lcs(text1, n - 1, text2, m);
        int ch2 = lcs(text1, n, text2, m - 1);

        return max(ch1, ch2);
    }
}
int main()
{
    string text1, text2;
    cin >> text1 >> text2;

    int n = text1.size();
    int m = text2.size();

    cout << lcs(text1, n, text2, m);
    return 0;
}