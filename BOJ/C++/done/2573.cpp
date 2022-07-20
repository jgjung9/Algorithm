/**
 * https://www.acmicpc.net/problem/2573
 *
 * solution:
 */
#include <iostream>
#include <vector>
using namespace std;
int n, m;
int board[300][300];
bool visited[300][300];
int cnt[300][300];
vector<pair<int, int>> iceberg;

const int dx[4] = {0, -1, 0, 1};
const int dy[4] = {-1, 0, 1, 0};

void DFS(int x, int y)
{
    visited[x][y] = true;

    for (int dir = 0; dir < 4; dir++)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            continue;
        if (board[nx][ny] == 0)
        {
            cnt[x][y]++;
            continue;
        }
        if (visited[nx][ny])
            continue;
        DFS(nx, ny);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
            if (board[i][j] > 0)
                iceberg.push_back(make_pair(i, j));
        }
    }
    for (int k = 0;; k++)
    {
        int count = 0, meltingCnt = 0;
        for (int i = 0; i < iceberg.size(); i++)
        {
            int x = iceberg[i].first, y = iceberg[i].second;
            if (!visited[x][y] && board[x][y])
            {
                DFS(x, y);
                count++;
            }
            visited[x][y] = false;
        }

        for (int i = 0; i < iceberg.size(); i++)
        {
            int x = iceberg[i].first, y = iceberg[i].second;
            board[x][y] = board[x][y] - cnt[x][y];
            cnt[x][y] = 0;
            if (board[x][y] <= 0)
            {
                board[x][y] = 0;
                meltingCnt++;
            }
        }

        if (count > 1)
        {
            cout << k;
            break;
        }

        if (iceberg.size() == meltingCnt)
        {
            cout << 0;
            break;
        }
    }
    return 0;
}