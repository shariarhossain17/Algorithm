#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
typedef pair<int, int> pii;
char ar[N][N];
bool visited[N][N];
vector<pair<int, int>> path = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int dist[N][N];
int n, m;

bool flag = false;
bool isValid(int cI, int cJ)
{
    if (cI >= 0 && cI < n && cJ >= 0 && cJ < m && ar[cI][cJ] == '.')
        return true;
    else
        return false;
}
void bfs(int sI, int sJ, int dI, int dJ)
{
    queue<pii> pq;
    pq.push({sI, sJ});
    visited[sI][sJ] = true;
    dist[sI][sJ] = 0;

    while (!pq.empty())
    {
        pii p = pq.front();
        int pI = p.first;
        int pJ = p.second;
        pq.pop();

        for (int i = 0; i < 4; i++)
        {
            pii v = path[i];
            int cI = pI + v.first;
            int cJ = pJ + v.second;

            if (cI == dI && cJ == dJ)
            {
                flag = true;
            }

            if (isValid(cI, cJ) && !visited[cI][cJ] && ar[cI][cJ] == '.')
            {
                visited[cI][cJ] = true;
                pq.push({cI, cJ});
                dist[cI][cJ] = dist[pI][pJ] + 1;
            }
        }
    }
};
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

    int sI, sJ, dI, dJ;
    cin >> sI >> sJ >> dI >> dJ;

    bfs(sI, sJ, dI, dJ);

    if (flag)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}