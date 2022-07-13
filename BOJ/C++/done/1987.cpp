/**
 * https://www.acmicpc.net/problem/1987
 *
 * solution: DFS 방식을 활용한 Backtracking
 * 알파벳 방문여부를 확인하는 visited 배열을 선언하고
 * 다음 좌표의 알파벳을 이미 방문한 경우 방문하지 않음
 * 방문횟수를 매번 최대값과 비교해 갱신하고 최종 결과값을 출력
 */
#include <iostream>
#include <string>
using namespace std;
int r, c, ans = 0;
string row;
char board[20][20];
bool visited[26] = {false};

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};
void solve(int x, int y, int cnt)
{
    visited[board[x][y] - 'A'] = true;
    ans = max(ans, cnt);

    for (int dir = 0; dir < 4; dir++)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx < 0 || nx >= r || ny < 0 || ny >= c)
            continue;
        if (visited[board[nx][ny] - 'A'])
            continue;
        solve(nx, ny, cnt + 1);
    }
    visited[board[x][y] - 'A'] = false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        cin >> row;
        for (int j = 0; j < c; j++)
            board[i][j] = row[j];
    }
    solve(0, 0, 1);
    cout << ans;
    return 0;
}