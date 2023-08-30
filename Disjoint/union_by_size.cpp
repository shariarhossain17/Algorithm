#include <bits/stdc++.h>
using namespace std;

int n, m;
int parent[1000];
int parentSize[1000];

void set_value(int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = -1;
        parentSize[i] = 1;
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
        if (parentSize[parentA] > parentSize[parentB])
        {
            parentSize[parentB] = parentA;
            parentSize[parentA] += parentSize[parentB];
        }
        else
        {
            parentSize[parentA] = parentB;
            parentSize[parentB] += parentSize[parentA];
        }
    }
}
int main()
{

    cin >> n >> m;
    set_value(n);

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