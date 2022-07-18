/**
 * https://www.acmicpc.net/problem/16954
 *
 * solution: BFS를 이용해 최단거리를 구한다.
 * 매 시간이 지날때마다 벽을 이동시켜준다.
 */
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
using namespace std;
char board[8][8];
vector<pair<int, int>> wallPos;
const int dx[9] = {0, -1, 0, 1, -1, -1, 1, 1, 0};
const int dy[9] = {-1, 0, 1, 0, -1, 1, -1, 1, 0};
vector<bool> dep(1000, false);

void moveWall()
{
    vector<pair<int, int>> newWallPos;
    for (int i = 0; i < wallPos.size(); i++)
    {
        int x = wallPos[i].first, y = wallPos[i].second;
        board[x][y] = '.';
        int nx = x + 1;
        if (nx >= 8)
            continue;
        newWallPos.push_back(make_pair(nx, y));
    }

    for (int i = 0; i < newWallPos.size(); i++)
    {
        int x = newWallPos[i].first, y = newWallPos[i].second;
        board[x][y] = '#';
    }
    wallPos = newWallPos;
}

void BFS(int x, int y)
{
    queue<tuple<int, int, int>> q;
    q.push(make_tuple(x, y, 0));
    int dist;
    while (!q.empty())
    {
        tie(x, y, dist) = q.front(), q.pop();

        if (!dep[dist])
        {
            dep[dist] = true;
            moveWall();
        }
        if (x == 0 && y == 7)
        {
            cout << 1;
            return;
        }
        for (int dir = 0; dir < 9; dir++)
        {
            int nx = x + dx[dir];
            int nnx = nx - 1;
            int ny = y + dy[dir];
            if (nx < 0 || nx >= 8 || ny < 0 || ny >= 8)
                continue;
            if (board[nx][ny] == '#')
                continue;
            if (nnx >= 0 && board[nnx][ny] == '#')
                continue;
            q.push(make_tuple(nx, ny, dist + 1));
        }
    }
    cout << 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    for (int i = 0; i < 8; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < 8; j++)
        {
            board[i][j] = str[j];
            if (board[i][j] == '#')
                wallPos.push_back(make_pair(i, j));
        }
    }
    dep[0] = true;
    BFS(7, 0);
    return 0;
}