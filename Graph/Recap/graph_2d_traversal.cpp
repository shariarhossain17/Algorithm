#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int N = 1e3 + 5;

bool visited[N][N];
int dist[N][N];

vector<pii> path = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m;
bool isValid(int cI, int cJ)
{
    if (cI >= 0 && cI < n && cJ >= 0 && cJ < m)
        return true;
    else
        return false;
}
void bfs_traverse_2d(int si, int sj)
{
    queue<pii> q;
    q.push({si, sj});
    visited[si][sj] = true;
    dist[si][sj] = 0;

    while (!q.empty())
    {
        pii parent = q.front();
        int pi = parent.first;
        int pj = parent.second;

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            pii p = path[i];
            int cI = pi + p.first;
            int cJ = pj + p.second;

            if (isValid(cI, cJ) && !visited[cI][cJ])
            {
                visited[cI][cJ] = true;
                q.push({cI, cJ});
                dist[cI][cJ] = dist[pi][pj] + 1;
            }
        }
    }
}
int main()
{

    cin >> n >> m;

    char ar[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> ar[i][j];
        }
    }

    int si, sj;
    cin >> si >> sj;

    bfs_traverse_2d(si, sj);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << dist[i][j] << " ";
        }

        cout << endl;
    }
    return 0;
}