#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int save[N];
int solved(int ar[], int n)
{

    if (n == 1)
        return 1;

    if (save[n] != -1)
    {
        return save[n];
    }
    if (n == 2)
    {
        return save[n] = abs(ar[2] - ar[1]);
    }
    else if (n >= 3)
    {
        int choice1 = solved(ar, n - 1) + abs(ar[n] - ar[n - 1]);
        int choice2 = solved(ar, n - 2) + abs(ar[n] - ar[n - 2]);

        return save[n] = min(choice1, choice2);
    }
};
int main()
{
    int n;
    cin >> n;
    int ar[n + 1];

    for (int i = 1; i <= n; i++)
    {
        cin >> ar[i];
        save[i] = -1;
    }

    cout << solved(ar, n);
    return 0;
}