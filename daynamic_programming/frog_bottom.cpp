#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int ar[n + 1], save[n + 1];

    for (int i = 1; i <= n; i++)
    {
        cin >> ar[i];
    }

    save[1] = 0;
    save[2] = abs(save[2] - save[1]);
    for (int i = 3; i <= n; i++)
    {
        int choice1 = save[i - 2] + abs(ar[i] - ar[i - 2]);
        int choice2 = save[i - 1] + abs(ar[i] - ar[i - 1]);

        ar[i] = min(choice1, choice2);
    }

    cout << ar[n];
    return 0;
}