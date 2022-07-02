/**
 * https://www.acmicpc.net/problem/2206
 *
 * solution: BFS를 활용한 최단거리 문제
 * 그래프의 노드를 x, y, 벽돌의 개수로 생각하고 방문을 진행한다.
 * 처음 끝점에 도달했을 때의 거리를 출력하고 BFS를 종료한다.
 */
#include <iostream>
#include <queue>
#include <string>
#include <tuple>
using namespace std;
int n, m;
int board[1000][1000];
int visited[1000][1000][2] = {0};

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};
void BFS(int x, int y)
{
    queue<tuple<int, int, int>> q;
    int brick = 0, dist = 1;
    visited[x][y][brick] = dist;
    q.push(make_tuple(x, y, brick));

    while (!q.empty())
    {
        tie(x, y, brick) = q.front();
        dist = visited[x][y][brick];
        q.pop();

        if (x == (n - 1) && y == (m - 1))
        {
            cout << dist;
            return;
        }

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            int nDist = dist + 1;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;

            if (brick == 1)
            {
                if (board[nx][ny] == 1)
                    continue;
                if (visited[nx][ny][brick] > 0 && visited[nx][ny][brick] <= nDist)
                    continue;
                visited[nx][ny][brick] = nDist;
                q.push(make_tuple(nx, ny, brick));
            }
            else
            {
                if (board[nx][ny] == 1)
                {
                    int nBrick = brick + 1;
                    if (visited[nx][ny][nBrick] > 0)
                        continue;
                    visited[nx][ny][nBrick] = nDist;
                    q.push(make_tuple(nx, ny, nBrick));
                }
                else
                {
                    if (visited[nx][ny][brick])
                        continue;
                    visited[nx][ny][brick] = nDist;
                    q.push(make_tuple(nx, ny, brick));
                }
            }
        }
    }
    cout << -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    string s;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < m; j++)
            board[i][j] = s[j] - '0';
    }
    BFS(0, 0);
    return 0;
}