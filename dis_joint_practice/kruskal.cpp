#include <bits/stdc++.h>
using namespace std;

class Edges
{
public:
    int a;
    int b;
    int c;

    Edges(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

bool cmp(Edges a, Edges b)
{
    return a.c < b.c;
}

const int N = 1e5 + 5;
int parent[N];
int parentSize[N];
vector<int> v;
void set_parent(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        parentSize[i] = 1;
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
}

int main()
{

    int n, m;
    cin >> n >> m;

    set_parent(n);
    vector<Edges> edgeList;
    vector<Edges> ans;
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edgeList.push_back(Edges(a, b, c));
    }

    sort(edgeList.begin(), edgeList.end(), cmp);

    for (Edges p : edgeList)
    {
        int leaderA = find_set(p.a);
        int leaderB = find_set(p.b);

        if (leaderA == leaderB)
            continue;
        ans.push_back(p);
        set_union(p.a, p.b);
    }
    for (Edges p : ans)
    {
        cout << p.a << " " << p.b << " " << p.c << endl;
    }

    return 0;
}