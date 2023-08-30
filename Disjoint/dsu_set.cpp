#include <bits/stdc++.h>
using namespace std;

int n, m;
int parent[1000];

void set_value(int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = -1;
    }
}

int find(int node)
{
    while (parent[node] != -1)
    {
        node = parent[node];
    }

    return node;
}

void dsu_set(int a, int b)
{
    int parentA = find(a);
    int parentB = find(b);

    if (parentA != parentB)
    {
        parent[parentB] = parentA;
    }
}
int main()
{

    cin >> n >> m;
    set_value(7);

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        dsu_set(a, b);
    }

    for (int i = 0; i < n; i++)
    {
        cout << parent[i] << " ";
    }

    return 0;
}