#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n, m;

int visited[N][N];

vector<pair<int, int>> path = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

char ar[N][N];
int cnt;

bool isValid(int cI, int cJ)
{
    if (cI >= 0 && cI < n && cJ >= 0 && cJ < m && ar[cI][cJ] == '.')
        return true;
    else
        return false;
}
void dfs(int si, int sj)
{
    visited[si][sj] = true;
    cnt++;

    for (int i = 0; i < path.size(); i++)
    {
        pair<int, int> p = path[i];

        int cI = si + p.first;
        int cJ = sj + p.second;

        if (isValid(cI, cJ) && !visited[cI][cJ])
        {
            dfs(cI, cJ);
        }
    }
}
int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> ar[i][j];
        }
    }

    int mn = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (ar[i][j] == '.' && !visited[i][j])
            {
                cnt = 0;
                dfs(i, j);
                mn = min(mn, cnt);
            }
        }
    }

    if (mn == INT_MAX)
    {
        cout << -1;
    }
    else
    {
        cout << mn;
    }
    return 0;
}