#include <bits/stdc++.h>
using namespace std;
int main()
{

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int n;

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        pq.push({a, b});
    }

    while (!pq.empty())
    {
        pair<int, int> p = pq.top();
        int f = p.first;
        int s = p.second;
        pq.pop();
        cout << f << " " << s << endl;
    }

    return 0;
}