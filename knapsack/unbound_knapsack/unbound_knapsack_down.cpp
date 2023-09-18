#include <bits/stdc++.h>
using namespace std;

int unbound_knapsack(int n, int s, int v[], int w[])
{
    // base case
    if (n == 0 || s == 0)
        return 0;
    if (w[n - 1] <= s)
    {
        int ch1 = v[n - 1] + unbound_knapsack(n, s - w[n - 1], v, w);
        int ch2 = unbound_knapsack(n - 1, s, v, w);
        return max(ch1, ch2);
    }
    else
        return unbound_knapsack(n - 1, s, v, w);
}

int main()
{
    int n, s;
    cin >> n >> s;
    int v[n], w[n];

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }

    cout << unbound_knapsack(n, s, v, w);

    return 0;
}
