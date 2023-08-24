#include <bits/stdc++.h>
using namespace std;

// way no one
// void merge(int a[], int l, int mid, int r)
// {
//     int left_size = mid - l + 1;
//     int right_size = r - mid;

//     int L[left_size + 1];
//     int R[right_size + 1];

//     for (int i = l, j = 0; i <= mid; i++, j++)
//     {
//         L[j] = a[i];
//     }
//     for (int i = mid + 1, j = 0; i <= r; i++, j++)
//     {
//         R[j] = a[i];
//     }

//     L[left_size] = INT_MAX;
//     R[right_size] = INT_MAX;

//     int lp = 0, rp = 0, curr = 0;

//     for (int i = l; i <= r; i++)
//     {
//         if (L[lp] < R[rp])
//         {
//             a[i] = L[lp];
//             lp++;
//         }
//         else
//         {
//             a[i] = R[rp];
//             rp++;
//         }
//     }
// }

// way no two

void merge(int a[], int l, int mid, int r)
{

    int left_size = mid - l + 1;
    int right_size = r - mid;

    int L[left_size];
    int R[right_size];

    // updated the left array with all the left value
    for (int i = l, j = 0; i <= mid; i++, j++)
    {
        L[j] = a[i];
    }

    // updated the right array with all the right value
    for (int i = mid + 1, j = 0; i <= r; i++, j++)
    {
        R[j] = a[i];
    }

    // merge the left and right array

    int lp = 0, rp = 0;
    int curr = l;
    while (lp < left_size && rp < right_size)
    {
        if (L[lp] < R[rp])
        {
            a[curr] = L[lp];
            lp++;
        }
        else
        {
            a[curr] = R[rp];
            rp++;
        }

        curr++;
    }

    while (lp < left_size)
    {
        a[curr] = L[lp];
        lp++;
        curr++;
    }
    while (rp < right_size)
    {
        a[curr] = R[rp];
        rp++;
        curr++;
    }
}
void mergeSort(int a[], int l, int r)
{

    if (l < r)
    {
        int mid = (l + r) / 2;
        mergeSort(a, l, mid);     // left side divider left to mid
        mergeSort(a, mid + 1, r); // right side divider mid+1 to end of the array
        merge(a, l, mid, r);
    }
}
int main()
{
    int n;
    cin >> n;
    int ar[n];

    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }

    mergeSort(ar, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << ar[i] << " ";
    }

    return 0;
}