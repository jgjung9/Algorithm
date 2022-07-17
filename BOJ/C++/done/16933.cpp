/**
 * https://www.acmicpc.net/problem/16933
 *
 * solution: BFS
 * 정점을 좌표 부순벽 낮밤 으로 설정하고 (x, y, k, d)
 * BFS 탐색을 하여 최단거리를 구한다.
 */
#include <iostream>
#include <queue>
#include <string>
#include <tuple>
using namespace std;
int n, m, k;
int visited[1000][1000][11][2];
int board[1000][1000];
const int dx[4] = {0, -1, 0, 1};
const int dy[4] = {-1, 0, 1, 0};
void BFS(int x, int y)
{
    queue<tuple<pair<int, int>, int, int>> q;
    int day = 0, wall = 0, dist = 1;
    visited[x][y][wall][day] = dist;
    q.push(make_tuple(make_pair(x, y), wall, day));

    while (!q.empty())
    {
        pair<int, int> xy;
        tie(xy, wall, day) = q.front(), q.pop();
        tie(x, y) = xy;
        dist = visited[x][y][wall][day];

        if (x == (n - 1) && y == (m - 1))
        {
            cout << dist;
            return;
        }

        if (!visited[x][y][wall][(day + 1) % 2])
        {
            visited[x][y][wall][(day + 1) % 2] = dist + 1;
            q.push(make_tuple(make_pair(x, y), wall, (day + 1) % 2));
        }

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (board[nx][ny])
            {
                if (wall == k || day == 1)
                    continue;
                if (visited[nx][ny][wall + 1][(day + 1) % 2])
                    continue;
                visited[nx][ny][wall + 1][(day + 1) % 2] = dist + 1;
                q.push(make_tuple(make_pair(nx, ny), wall + 1, (day + 1) % 2));
            }
            else
            {
                if (visited[nx][ny][wall][(day + 1) % 2])
                    continue;
                visited[nx][ny][wall][(day + 1) % 2] = dist + 1;
                q.push(make_tuple(make_pair(nx, ny), wall, (day + 1) % 2));
            }
        }
    }
    cout << -1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++)
            board[i][j] = str[j] - '0';
    }
    BFS(0, 0);
    return 0;
}