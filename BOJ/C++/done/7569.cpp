/**
 * https://www.acmicpc.net/problem/7569
 *
 * solution: BFS를 이용해 모든 지점 방문한다.
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Position
{
    int x, y, z, depth;
};

// m : 가로(열) n : 세로 (행) h : 높이
int m, n, h;
int graph[100][100][100];
int visited[100][100][100] = {0};

const int dx[6] = {0, 0, -1, 1, 0, 0};
const int dy[6] = {-1, 1, 0, 0, 0, 0};
const int dz[6] = {0, 0, 0, 0, 1, -1};

void BFS(int x, int y, int z, int dep)
{
    queue<Position> q;
    visited[x][y][z] = dep;
    q.push({x, y, z, dep});

    while (!q.empty())
    {
        x = q.front().x, y = q.front().y, z = q.front().z;
        dep = q.front().depth;
        q.pop();
        for (int dir = 0; dir < 6; dir++)
        {
            int nextX = x + dx[dir];
            int nextY = y + dy[dir];
            int nextZ = z + dz[dir];
            if (nextX < 0 || nextX >= n)
                continue;
            if (nextY < 0 || nextY >= m)
                continue;
            if (nextZ < 0 || nextZ >= h)
                continue;
            if (graph[nextX][nextY][nextZ] != 0)
                continue;
            if (visited[nextX][nextY][nextZ] == 0)
            {
                visited[nextX][nextY][nextZ] = dep + 1;
                q.push({nextX, nextY, nextZ, dep + 1});
            }
            else if (visited[nextX][nextY][nextZ] > dep + 1)
            {
                visited[nextX][nextY][nextZ] = dep + 1;
                q.push({nextX, nextY, nextZ, dep + 1});
            }
        }
    }
}

bool done()
{
    for (int k = 0; k < h; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (graph[i][j][k] == 0)
                    return false;
            }
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> m >> n >> h;

    for (int k = 0; k < h; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> graph[i][j][k];

    if (done())
    {
        cout << 0;
        return 0;
    }

    for (int k = 0; k < h; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (graph[i][j][k] == 1)
                    BFS(i, j, k, 1);
            }
        }
    }

    int ans = 0;
    for (int k = 0; k < h; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (graph[i][j][k] == 0)
                {
                    if (visited[i][j][k] == 0)
                    {
                        cout << -1;
                        return 0;
                    }
                    else if (visited[i][j][k] > ans)
                        ans = visited[i][j][k];
                }
            }
        }
    }
    cout << ans - 1;
    return 0;
}