/**
 * https://www.acmicpc.net/problem/2178
 *
 * solution: BFS를 이용해 최단거리를 구해 출력한다.
 */
#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int visited[100][100] = {0};
int graph[100][100] = {0};
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
queue<vector<int>> q;

void BFS(int x, int y, int n, int m, int depth)
{
    if (visited[x][y])
        return;
    visited[x][y] = depth;
    for (int dir = 0; dir < 4; dir++)
    {
        int nextX = x + dx[dir];
        int nextY = y + dy[dir];
        if (nextX < 0 || nextX >= n)
            continue;
        if (nextY < 0 || nextY >= m)
            continue;
        if (graph[nextX][nextY] == 0)
            continue;
        if (visited[nextX][nextY])
            continue;
        q.push({nextX, nextY, depth + 1});
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        string row;
        cin >> row;
        for (int j = 0; j < m; j++)
            graph[i][j] = row[j] - '0';
    }
    BFS(0, 0, n, m, 1);
    while (!q.empty())
    {
        int x = q.front()[0];
        int y = q.front()[1];
        int depth = q.front()[2];
        q.pop();
        BFS(x, y, n, m, depth);
    }
    cout << visited[n - 1][m - 1];

    return 0;
}