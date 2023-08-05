#include <bits/stdc++.h>
using namespace std;

int binary_search(vector<int> &v, int target)
{
    int l = 0;
    int r = v.size() - 1;

    while (l <= r)
    {
        int mid = (l + r) / 2;

        if (v[mid] == target)
        {
            return v[mid];
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
    return -1;
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

    int result = binary_search(v, k);
    if (result == -1)
        cout << "Not Found";
    else
        cout << result;
    return 0;
}