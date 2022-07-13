/**
 * https://www.acmicpc.net/problem/2468
 *
 * solution: DFS를 이용한 나뉘어진 구역 개수 확인
 * 침수되어 갈 수 없는 좌표는 탐색하지 않는다.
 * DFS가 진행된 횟수가 나뉘어진 안전한 구역의 개수
 * 지역의 높이가 가장 낮은 곳 부터 가장 높은 곳까지 차례대로 침수되는 구역을 높혀가면
 * 나누어진 구역개수를 체크하고 최대값을 업데이트한다.
 */
#include <iostream>
#include <cstring>
using namespace std;
int n, ans = 1;
int board[100][100];
bool visited[100][100];

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};
void DFS(int x, int y, int h)
{
    visited[x][y] = true;

    for (int dir = 0; dir < 4; dir++)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n)
            continue;
        if (board[nx][ny] <= h || visited[nx][ny])
            continue;
        DFS(nx, ny, h);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n;
    int minH = 100;
    int maxH = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
            if (board[i][j] < minH)
                minH = board[i][j];
            if (board[i][j] > maxH)
                maxH = board[i][j];
        }
    }

    for (int h = minH; h <= maxH; h++)
    {
        int cnt = 0;
        memset(visited, false, sizeof(visited));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] > h && !visited[i][j])
                {
                    DFS(i, j, h);
                    cnt++;
                }
            }
        }
        ans = max(ans, cnt);
    }

    cout << ans;
    return 0;
}