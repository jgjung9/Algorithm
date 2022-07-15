#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
int n, r1, c1, r2, c2;
vector<vector<int>> visited(200, vector<int>(200, -1));

const int dx[6] = {-2, -2, 0, 0, 2, 2};
const int dy[6] = {-1, 1, -2, 2, -1, 1};
void BFS(int x, int y)
{
    queue<tuple<int, int, int>> q;
    int dist = 0;
    visited[x][y] = dist;
    q.push(make_tuple(x, y, dist));

    while (!q.empty())
    {
        tie(x, y, dist) = q.front();
        q.pop();

        for (int dir = 0; dir < 6; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
            if (visited[nx][ny] > -1)
                continue;
            visited[nx][ny] = dist + 1;
            q.push(make_tuple(nx, ny, dist + 1));
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n;
    cin >> r1 >> c1 >> r2 >> c2;

    BFS(r1, c1);
    cout << visited[r2][c2];
    return 0;
}