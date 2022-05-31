/**
 * https://www.acmicpc.net/problem/7562
 *
 * solution: 나이트가 갈 수 있는 방향으로 BFS를 진행하고
 * 매번 깊이를 저장하여 목표 지점에 도착할때 저장된 깊이를 반환한다.
 */
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int dy[8] = {-2, -2, 1, 2, 2, 1, -1, -2};
int dx[8] = {-1, -1, -2, -1, 1, 2, 2, 1};
queue<vector<int>> q;
bool visited[300][300] = {false};
bool found[300][300] = {false};
void BFS(int y, int x, int depth, int n)
{
    if (visited[y][x])
        return;
    visited[y][x] = true;
    for (int dir = 0; dir < 8; dir++)
    {
        int nextY = y + dy[dir];
        int nextX = x + dx[dir];
        if (nextY < 0 || nextY >= n)
            continue;
        if (nextX < 0 || nextX >= n)
            continue;
        if (found[nextY][nextX])
            continue;
        found[nextY][nextX] = true;
        q.push({nextY, nextX, depth + 1});
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
        int nowY, nowX, targetY, targetX;
        cin >> nowY >> nowX >> targetY >> targetX;

        if (nowY == targetY && nowX == targetX)
        {
            cout << 0 << '\n';
            continue;
        }
        BFS(nowY, nowX, i, 0);
        while (!q.empty())
        {
            vector<int> front = q.front();
            if (front[0] == targetY && front[1] == targetX)
            {
                cout << front[2] << '\n';
                break;
            }
            BFS(front[0], front[1], front[2], i);
            q.pop();
        }
    }
}