#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
int n, m, maxDep = 0;
int board[100][100];
bool visited[100][100] = {0};
int cnt[200] = {0};

queue<tuple<int, int, int>> q;
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

void DFS(int x, int y, int dep)
{
    for (int dir = 0; dir < 4; dir++)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            continue;
        if (visited[nx][ny])
            continue;
        if (board[nx][ny] == 0)
        {
            visited[nx][ny] = true;
            DFS(nx, ny, dep);
        }
        else
        {
            visited[nx][ny] = true;
            cnt[dep + 1] += 1;
            q.push(make_tuple(nx, ny, dep + 1));
        }
    }
}

void BFS()
{
    visited[0][0] = true;
    q.push(make_tuple(0, 0, 0));

    int x, y, dep;
    while (!q.empty())
    {
        tie(x, y, dep) = q.front();
        q.pop();
        maxDep = max(maxDep, dep);
        board[x][y] = 0;
        DFS(x, y, dep);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    BFS();
    cout << maxDep << '\n';
    cout << cnt[maxDep];
    return 0;
}
