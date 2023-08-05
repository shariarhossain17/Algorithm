#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int ar[N];

void merge(int l, int mid, int r)
{
    int left_size = (mid - l) + r;
    int L[left_size + 1];
    int right_size = r - mid;
    int R[right_size + 1];

    for (int i = l, j = 0; i <= mid; i++, j++)
    {
        L[j] = ar[i];
    }

    for (int i = mid + 1, j = 0; i <= r; i++, j++)
    {
        R[j] = ar[i];
    }

    L[left_size] = INT_MAX;
    R[right_size] = INT_MAX;

    int lp = 0, rp = 0;
    for (int i = l; i <= r; i++)
    {
        if (L[lp] <= R[rp])
        {
            ar[i] = L[lp];
            lp++;
        }
        else
        {
            ar[i] = R[rp];
            rp++;
        }
    }
}
void mergesort(int l, int r) //
{

    if (l == r)
        return;
    int mid = (l + r) / 2;

    mergesort(l, mid);
    mergesort(mid + 1, r);
    merge(l, mid, r);
}
int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }

    mergesort(0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << ar[i] << " ";
    }
    return 0;
}