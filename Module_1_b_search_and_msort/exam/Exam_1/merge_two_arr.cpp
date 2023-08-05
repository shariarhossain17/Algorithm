#include <bits/stdc++.h>
using namespace std;

void merge(int a1[], int a2[], int n, int m, int result[])
{
    int x = 0, y = 0, k = 0;

    while (n > x && m > y)
    {
        if (a1[x] > a2[y])
        {
            result[k++] = a1[x++];
        }
        else
        {
            result[k++] = a2[y++];
        }
    }

    while (x < n)
    {
        result[k++] = a1[x++];
    }
    while (y < m)
    {
        result[k++] = a2[y++];
    }
}
int main()
{
    int n, m;
    cin >> n;
    int a1[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a1[i];
    }
    cin >> m;
    int a2[m];

    for (int i = 0; i < m; i++)
    {
        cin >> a2[i];
    }

    int result[n + m];

    merge(a1, a2, n, m, result);

    for (int i = 0; i < n + m; i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}