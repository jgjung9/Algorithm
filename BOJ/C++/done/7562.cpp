/**
 * https://www.acmicpc.net/problem/7562
 *
 * solution: 나이트가 갈 수 있는 방향으로 BFS를 진행하고
 * 매번 깊이를 저장하여 목표 지점에 도착할때 저장된 깊이를 반환한다.
 */
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
queue<vector<int>> q;

int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
void BFS(int x, int y, int n, int depth, int visited[][300])
{
    if (visited[x][y])
        return;
    visited[x][y] = depth;
    for (int dir = 0; dir < 8; dir++)
    {
        int nextX = x + dx[dir];
        int nextY = y + dy[dir];
        if (nextX < 0 || nextX >= n)
            continue;
        if (nextY < 0 || nextY >= n)
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
    int t;
    cin >> t;
    while (t--)
    {
        int i;
        int depth;
        int startX, startY, targetX, targetY;
        int visited[300][300] = {0};
        cin >> i;
        cin >> startX >> startY >> targetX >> targetY;
        BFS(startX, startY, i, 1, visited);
        while (!q.empty())
        {
            int x = q.front()[0];
            int y = q.front()[1];
            int dep = q.front()[2];
            q.pop();
            BFS(x, y, i, dep, visited);
        }
        cout << visited[targetX][targetY] - 1 << '\n';
    }
    return 0;
}