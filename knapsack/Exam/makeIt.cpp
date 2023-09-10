#include <iostream>
#include <vector>
using namespace std;

void make_it(int N, vector<bool> &v)
{
    v[1] = true;
    for (int i = 1; i <= N; i++)
    {
        if (v[i])
        {
            if (i + 3 <= N)
            {
                v[i + 3] = true;
            }
            if (i * 2 <= N)
            {
                v[i * 2] = true;
            }
        }
    }
}

int main()
{
    int T;
    cin >> T;
    int maxN = 100000;
    vector<bool> v(maxN + 1, false);
    make_it(maxN, v);

    while (T--)
    {
        int N;
        cin >> N;

        if (v[N])
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
