/**
 * https://www.acmicpc.net/problem/6087
 *
 * solution: BFS
 * 정점을 좌표와 방향으로 설정하고
 * 방문시 사용한 거울의 양이 기존 거울 사용량보다 작을 경우 방문한다.
 * 방향의 90회전이 가능하고 180도는 불가하므로
 * dx, dy를 좌 상 우 하 로 설정해 각 방향 + 2 % 4 를 할 경우
 * 180도 회전한 방향으로 설정되도록 만들어 해당 경우를 제외해준다.
 */
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <tuple>
using namespace std;
const int INF = 1e9;
int w, h;
char board[100][100];
int visited[1000][1000][4];
vector<pair<int, int>> target;
const int dx[] = {0, -1, 0, 1};
const int dy[] = {-1, 0, 1, 0};

void BFS(int x, int y)
{
    queue<tuple<int, int, int>> q;
    int mirror = 0;
    int direction;
    visited[x][y][0] = mirror;

    for (int dir = 0; dir < 4; dir++)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx < 0 || nx >= h || ny < 0 || ny >= w)
            continue;
        if (board[nx][ny] == '*')
            continue;
        visited[nx][ny][dir] = mirror;
        q.push(make_tuple(nx, ny, dir));
    }

    while (!q.empty())
    {
        tie(x, y, direction) = q.front(), q.pop();
        mirror = visited[x][y][direction];
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= h || ny < 0 || ny >= w)
                continue;
            if ((direction + 2) % 4 == dir)
                continue;
            if (board[nx][ny] == '*')
                continue;
            if (direction == dir)
            {
                if (visited[nx][ny][dir] > mirror)
                {
                    visited[nx][ny][dir] = mirror;
                    q.push(make_tuple(nx, ny, dir));
                }
            }
            else
            {
                if (visited[nx][ny][dir] > mirror + 1)
                {
                    visited[nx][ny][dir] = mirror + 1;
                    q.push(make_tuple(nx, ny, dir));
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> w >> h;
    for (int i = 0; i < h; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < w; j++)
        {
            board[i][j] = str[j];
            if (board[i][j] == 'C')
                target.push_back(make_pair(i, j));
        }
    }
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            for (int dir = 0; dir < 4; dir++)
                visited[i][j][dir] = INF;
    BFS(target[0].first, target[0].second);
    int ans = INF;
    for (int i = 0; i < 4; i++)
        ans = min(ans, visited[target[1].first][target[1].second][i]);
    cout << ans;
    return 0;
}