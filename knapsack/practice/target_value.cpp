#include <bits/stdc++.h>
using namespace std;

bool targeted_value(long long int currentValue, long long int target)
{
    if (currentValue == target)
        return true;

    if (currentValue > target)
        return false;

    return targeted_value(currentValue * 10, target) || targeted_value(currentValue * 20, target);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;

        if (targeted_value(1, n))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
