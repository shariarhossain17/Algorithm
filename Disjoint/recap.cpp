#include <bits/stdc++.h>
using namespace std;

int parent[1000];
int parent_size[1000];

void dsu_set(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        parent_size[i] = 1;
    }
}
int find(int node)
{
    if (parent[node] != node)
    {
        parent[node] = find(parent[node]);
    }

    return parent[node];
}

void union_set(int u, int v)
{
    int parentA = find(u);
    int parentB = find(v);

    if (parentA != parentB)
    {
        if (parent_size[parentA] > parent_size[parentB])
        {
            parent[parentB] = parentA;
            parent_size[parentA] += parent_size[parentB];
        }

        else
        {
            parent[parentA] = parentB;
            parent_size[parentB] += parent_size[parentA];
        }
    }
}
int main()
{

    int n, m;
    cin >> n >> m;

    dsu_set(n);

    while (m--)
    {
        int a, b;
        cin >> a >> b;

        int parentA = find(a);
        int parentB = find(b);

        if (parentA == parentB)
            cout << "cycle detected";
        else
            union_set(a, b);
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << parent[i] << " ";
    // }
    return 0;
}