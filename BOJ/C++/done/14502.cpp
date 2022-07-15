/**
 * https://www.acmicpc.net/problem/14502
 *
 * solution: DFS + 브루트 포스
 * 최대 n: 8 m: 8 => 8x8 에서 3개를 골라 벽을 설치하고
 * 바이러스가 지나가는 자리의 개수를 세어준다.
 * n x m 칸중 3개를 선택하는 경우의 수 nmC3 => 약 (nm)^3 / 6
 * n x m 칸을 탐색하는 시간 복잡도 O(nm)
 * 따라서 O(nm^4)의 복잡도를 가진다.
 * (2^6)^4 => 2^24 => 약 1600만 시간 제한 2초로 충분함
 */
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int n, m, cnt, ans = 0, wallCnt = 0;
int board[8][8];
bool visited[8][8];
vector<pair<int, int>> virus;

const int dx[4] = {0, -1, 0, 1};
const int dy[4] = {-1, 0, 1, 0};

void DFS(int x, int y)
{
    visited[x][y] = true;
    cnt++;
    for (int dir = 0; dir < 4; dir++)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            continue;
        if (board[nx][ny] != 0)
            continue;
        if (visited[nx][ny])
            continue;
        DFS(nx, ny);
    }
}

void makeWall(int idx, int wall)
{
    if (wall == 3)
    {
        memset(visited, false, sizeof(visited));
        int sum = 0;
        cnt = 0;
        for (int i = 0; i < virus.size(); i++)
            DFS(virus[i].first, virus[i].second);
        sum += cnt;
        ans = max(ans, n * m - wallCnt - wall - sum);
        return;
    }
    if (idx == n * m)
        return;

    int x = idx / m;
    int y = idx % m;
    if (board[x][y] == 0)
    {
        board[x][y] = 1;
        makeWall(idx + 1, wall + 1);
        board[x][y] = 0;
    }
    makeWall(idx + 1, wall);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 2)
                virus.push_back(make_pair(i, j));
            else if (board[i][j] == 1)
                wallCnt++;
        }
    }
    makeWall(0, 0);
    cout << ans;
    return 0;
}