/**
 * https://www.acmicpc.net/problem/1261
 *
 * solution: BFS를 이용해 점을 방문한다.
 * 방문했을 시 뚫고 지난간 벽의 개수를 visited에 넣어준다.
 * 다른 벽을 뚫고 이미 방문한 벽을 다시 방문할 경우네는
 * 뚫은 벽의 개수가 더 작을 때만 하도록 처리한다.
 * 이미 방문한 벽을 다시 방문해야 하는 경우는 현재까지 둟은 벽의 개수 + 1 보다
 * 큰 경우만 해당하도록 처리한다.
 */
#include <iostream>
#include <queue>
#include <tuple>
#include <string>
using namespace std;

int m, n;
bool graph[100][100];
int visited[100][100];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void BFS(int x, int y, int wall)
{
    queue<tuple<int, int, int>> q;
    visited[x][y] = wall;
    q.push(make_tuple(x, y, wall));

    while (!q.empty())
    {
        tie(x, y, wall) = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nextX = x + dx[dir];
            int nextY = y + dy[dir];
            if (nextX < 0 || nextX >= n)
                continue;
            if (nextY < 0 || nextY >= m)
                continue;
            if (visited[nextX][nextY] <= wall)
                continue;

            if (graph[nextX][nextY])
            {
                if (visited[nextX][nextY] > wall + 1)
                {
                    visited[nextX][nextY] = wall + 1;
                    q.push(make_tuple(nextX, nextY, wall + 1));
                }
            }
            else
            {
                visited[nextX][nextY] = wall;
                q.push(make_tuple(nextX, nextY, wall));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m >> n;
    string row;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            visited[i][j] = 200;

    for (int i = 0; i < n; i++)
    {
        cin >> row;
        for (int j = 0; j < m; j++)
            graph[i][j] = row[j] - '0';
    }

    BFS(0, 0, 0);
    cout << visited[n - 1][m - 1];
    return 0;
}