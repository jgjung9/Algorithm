/**
 * https://www.acmicpc.net/problem/1303
 *
 * solution: DFS
 */
#include <iostream>
#include <string>
using namespace std;
int n, m, w = 0, b = 0;
char board[100][100];
bool visited[100][100];
const int dx[] = {0, -1, 0, 1};
const int dy[] = {-1, 0, 1, 0};

int DFS(int x, int y, char team)
{
    visited[x][y] = true;
    int cnt = 1;
    for (int dir = 0; dir < 4; dir++)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx < 0 || nx >= m || ny < 0 || ny >= n)
            continue;
        if (board[nx][ny] != team || visited[nx][ny])
            continue;
        cnt += DFS(nx, ny, team);
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++)
            board[i][j] = s[j];
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j])
            {
                int res = DFS(i, j, board[i][j]);
                board[i][j] == 'W' ? w += res *res : b += res * res;
            }
        }
    }
    cout << w << ' ' << b;
    return 0;
}