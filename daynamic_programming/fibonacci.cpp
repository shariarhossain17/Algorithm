#include <bits/stdc++.h>
using namespace std;

int fibonacci(int n)
{
    if (n <= 1)
        return 1;

    int ans1 = fibonacci(n - 1);
    int ans2 = fibonacci(n - 2);
    return ans1 + ans2;
}
int main()
{
    int n;
    cin >> n;

    cout << fibonacci(n);
    return 0;
}