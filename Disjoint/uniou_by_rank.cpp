#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int parent[N];
int parentLevel[N];
vector<int> v;
void set_parent(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        parentLevel[i] = 0;
    }
}

int find_set(int node)
{
    if (parent[node] != node)
    {
        parent[node] = find_set(parent[node]);
    }
    return parent[node];
}

void set_union(int a, int b)
{
    int leaderA = find_set(a);
    int leaderB = find_set(b);

    if (leaderA != leaderB)
    {
        if (parentLevel[leaderA] > parentLevel[leaderB])
        {
            parent[leaderB] = leaderA;
        }
        else if (parentLevel[leaderB] > parentLevel[leaderA])
        {
            parent[leaderA] = leaderB;
        }
        else
        {
            parent[leaderB] = leaderA;
            parentLevel[leaderA]++;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int m = n - 1;

    set_parent(n);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        int leaderA = find_set(a);
        int leaderB = find_set(b);

        if (leaderA == leaderB)
        {
            v.push_back(a);
            v.push_back(b);
        }
        else
        {
            set_union(a, b);
        }
    }

    map<int, bool> mp;

    for (int i = 1; i <= n; i++)
    {
        int ldr = find_set(i);
        mp[ldr] = true;
    }

    vector<int> v2;
    for (pair<int, bool> p : mp)
    {
        v2.push_back(p.first);
    }

    cout << v2.size() - 1 << endl;

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    for (int i = 0; i < v2.size(); i++)
    {
        if (!v2[i] != 1)
        {
            cout << v2[i] << " ";
        }
    }

    return 0;
}
