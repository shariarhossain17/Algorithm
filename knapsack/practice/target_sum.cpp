#include <bits/stdc++.h>
using namespace std;

bool canExpression(int ci, int cs, int t, int n, int ar[])
{
    if (ci == n)
        return cs == t;

    int choice1 = canExpression(ci + 1, cs + ar[ci], t, n, ar);
    int choice2 = canExpression(ci + 1, cs - ar[ci], t, n, ar);

    if (choice1 || choice2)
        return true;

    return false;
}
int main()
{
    int n, t;
    cin >> n >> t;
    int ar[n];

    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }

    if (canExpression(1, ar[0], t, n, ar))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}