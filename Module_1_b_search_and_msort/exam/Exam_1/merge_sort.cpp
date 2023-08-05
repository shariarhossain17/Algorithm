#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int ar[N];

void merge(int l, int r, int mid)
{
    int left_size = mid - l + 1;
    int left[left_size + 1];
    int right_size = r - mid;
    int right[right_size + 1];

    for (int i = l, j = 0; i <= mid; i++, j++)
    {
        left[j] = ar[i];
    }

    for (int i = mid + 1, j = 0; i <= r; i++, j++)
    {
        right[j] = ar[i];
    }

    left[left_size] = INT_MIN;
    right[right_size] = INT_MIN;

    int lp = 0, rp = 0;
    for (int i = l; i <= r; i++)
    {

        if (left[lp] >= right[rp])
        {
            ar[i] = left[lp];
            lp++;
        }
        else
        {
            ar[i] = right[rp];
            rp++;
        }
    }
}
void mergesort(int l, int r)
{
    if (l == r)
        return;

    int mid = (l + r) / 2;

    mergesort(l, mid);
    mergesort(mid + 1, r);
    merge(l, r, mid);
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