/**
 * https://www.acmicpc.net/problem/14503
 *
 * solution: DFS 방식으로 진행하지만
 * 재귀적으로 뒤로 돌아 갔을 때 그 지점에서 다시 탐색하진 않는다.
 */
#include <iostream>
using namespace std;
int n, m, r, c, d, cnt = 0;
int board[50][50];
bool visited[50][50] = {false};

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
void cleaning(int x, int y, int dir)
{
    if (!visited[x][y])
    {
        visited[x][y] = true;
        cnt++;
    }

    int nx, ny, nd;
    for (int i = 1; i <= 4; i++)
    {
        nd = (4 + dir - i) % 4;
        nx = x + dx[nd];
        ny = y + dy[nd];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            continue;
        if (board[nx][ny] == 1)
            continue;
        if (visited[nx][ny])
            continue;
        cleaning(nx, ny, nd);
        return;
    }

    nx = x - dx[dir];
    ny = y - dy[dir];
    if (nx < 0 || nx >= n || ny < 0 || ny >= m)
        return;
    if (board[nx][ny] == 1)
        return;
    cleaning(nx, ny, dir);
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m;
    cin >> r >> c >> d;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    cleaning(r, c, d);
    cout << cnt;
    return 0;
}