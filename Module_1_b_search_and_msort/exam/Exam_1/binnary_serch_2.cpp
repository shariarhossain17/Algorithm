#include <bits/stdc++.h>
using namespace std;

int first_search(vector<int> &v, int target)
{
    int l = 0;
    int r = v.size() - 1;
    int count = 0;

    while (l <= r)
    {
        int mid = (l + r) / 2;

        if (v[mid] == target)
        {
            count++;
            r = mid - 1;
        }
        else if (v[mid] < target)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return count;
};
int second_search(vector<int> &v, int target)
{
    int l = 0;
    int r = v.size() - 1;
    int count = 0;

    while (l <= r)
    {
        int mid = (l + r) / 2;

        if (v[mid] == target)
        {
            count++;
            l = mid + 1;
        }
        else if (v[mid] < target)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    return count;
};
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int k;
    cin >> k;

    int result1 = first_search(v, k);
    int result2 = second_search(v, k);

    if (result2 - result1 > 0)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}