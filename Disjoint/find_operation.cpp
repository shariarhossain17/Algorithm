#include <bits/stdc++.h>
using namespace std;

int ar[8] = {-1, -1, 1, 1, 6, 4, -1, -1};

void find(int n)
{
    while (ar[n] != -1)
    {
        n = ar[n];
    }

    cout << n;
}
int main()
{
    find(1);
    return 0;
}