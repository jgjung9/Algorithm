/**
 * https://www.acmicpc.net/problem/14442
 *
 * solution: 노드를 (x, y, k)로 설정하고
 * BFS를 진행하여 최소거리를 찾는다.
 */
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <string>
using namespace std;
int n, m, k;
int visited[1000][1000][10];
int board[1000][1000];
const int dx[4] = {0, -1, 0, 1};
const int dy[4] = {-1, 0, 1, 0};

void BFS(int x, int y)
{
    queue<tuple<int, int, int>> q;
    int dist = 1, wall = 0;
    visited[x][y][0] = dist;
    q.push(make_tuple(x, y, wall));

    while (!q.empty())
    {
        tie(x, y, wall) = q.front(), q.pop();
        dist = visited[x][y][wall];

        if (x == (n - 1) && y == (m - 1))
        {
            cout << dist;
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
                if (wall == k)
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