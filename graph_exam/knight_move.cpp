#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

int bfs(int N, int M, int K_i, int K_j, int Q_i, int Q_j)
{
    vector<vector<int>> dist(N, vector<int>(M, -1));
    queue<pair<int, int>> q;
    q.push({K_i, K_j});
    dist[K_i][K_j] = 0;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == Q_i && y == Q_j)
        {
            return dist[x][y];
        }

        for (int i = 0; i < 8; ++i)
        {
            int dI = x + dx[i];
            int dJ = y + dy[i];

            if (dI >= 0 && dI < N && dJ >= 0 && dJ < M && dist[dI][dJ] == -1)
            {
                dist[dI][dJ] = dist[x][y] + 1;
                q.push({dI, dJ});
            }
        }
    }

    return -1;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N, M;
        cin >> N >> M;

        int K_i, K_j, Q_i, Q_j;
        cin >> K_i >> K_j >> Q_i >> Q_j;

        int steps = bfs(N, M, K_i, K_j, Q_i, Q_j);

        cout << steps << endl;
    }

    return 0;
}
