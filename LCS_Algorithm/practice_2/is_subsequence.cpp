#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s, t;
    cin >> s >> t;

    int x = 0;
    bool ans = false;
    for (char c : t)
    {
        if (c == s[x])
        {
            x++;
        }

        if (x == s.size())
        {
            ans = true;
            break;
        }
    }

    if (ans)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}