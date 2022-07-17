/**
 * https://www.acmicpc.net/problem/14923
 *
 * solution: 정점을 좌표와 부순 벽의 개수로 잡는다 (x, y, k)
 * BFS를 통해 최단거리를 계산하고 출력한다.
 */
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
int n, m, hx, hy, ex, ey;
int visited[1000][1000][2];
int board[1000][1000];
const int dx[4] = {0, -1, 0, 1};
const int dy[4] = {-1, 0, 1, 0};
void BFS(int x, int y)
{
    queue<tuple<int, int, int>> q;
    int dist = 1, wall = 0;
    visited[x][y][wall] = dist;
    q.push(make_tuple(x, y, wall));

    while (!q.empty())
    {
        tie(x, y, wall) = q.front(), q.pop();
        dist = visited[x][y][wall];

        if (x == (ex - 1) && y == (ey - 1))
        {
            cout << dist - 1;
            return;
        }

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (board[nx][ny])
            {
                if (wall == 1)
                    continue;
                if (visited[nx][ny][wall + 1])
                    continue;
                visited[nx][ny][wall + 1] = dist + 1;
                q.push(make_tuple(nx, ny, wall + 1));
            }
            else
            {
                if (visited[nx][ny][wall])
                    continue;
                visited[nx][ny][wall] = dist + 1;
                q.push(make_tuple(nx, ny, wall));
            }
        }
    }
    cout << -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m >> hx >> hy >> ex >> ey;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    BFS(hx - 1, hy - 1);
    return 0;
}