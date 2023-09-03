#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int parent[N];
int parentSize[N];

void dsu_parent(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        parentSize[i] = 1;
    }
}

int dsu_find(int n)
{
    if (parent[n] != n)
    {
        parent[n] = dsu_find(parent[n]);
    }
    return parent[n];
}

void dsu_union(int a, int b)
{

    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);
    if (parentSize[leaderA] > parentSize[leaderB])
    {
        parent[leaderB] = leaderA;
        parentSize[leaderA] += parentSize[leaderB];
    }
    else
    {
        parent[leaderA] = leaderB;
        parentSize[leaderB] += parentSize[leaderA];
    }
}
int main()
{
    int n, m;
    cin >> n >> m;

    dsu_parent(n);
    int cnt = 0;

    while (m--)
    {
        int a, b;
        cin >> a >> b;

        int leaderA = dsu_find(a);
        int leaderB = dsu_find(b);

        if (leaderA == leaderB)
            cnt++;
        else
            dsu_union(a, b);
    }

    cout << cnt;

    return 0;
}