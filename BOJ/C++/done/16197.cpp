/**
 * https://www.acmicpc.net/problem/16197
 *
 * solution: Brute Force (Backtracking)
 * 동전을 움직이는 횟수가 10번이 넘을 경우 종료
 * 동전이 둘다 빠진경우 종료
 * 동전이 하나만 빠진경우 움직임 횟수 출력
 * 최대 10번까지 움직이고 4방향으로 움직일 수 있으므로
 * 경우의 수는 4^10이다 약 백만 -> 브루트 포스로 충분히 해결가능한 수치
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int n, m, ans = 11;
char board[20][20];
vector<pair<int, int>> coinPos;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};
void solve(int move, int x1, int y1, int x2, int y2)
{
    if (move == 11)
        return;

    bool coin1 = (x1 < 0 || x1 >= n || y1 < 0 || y1 >= m);
    bool coin2 = (x2 < 0 || x2 >= n || y2 < 0 || y2 >= m);
    if (coin1 && coin2)
        return;
    else if (coin1 || coin2)
    {
        ans = min(ans, move);
        return;
    }

    for (int dir = 0; dir < 4; dir++)
    {
        int nx1 = x1 + dx[dir];
        int ny1 = y1 + dy[dir];
        int nx2 = x2 + dx[dir];
        int ny2 = y2 + dy[dir];
        if (0 <= nx1 && nx1 < n && 0 <= ny1 && ny1 < m)
        {
            if (board[nx1][ny1] == '#')
                nx1 = x1, ny1 = y1;
        }
        if (0 <= nx2 && nx2 < n && 0 <= ny2 && ny2 < m)
        {
            if (board[nx2][ny2] == '#')
                nx2 = x2, ny2 = y2;
        }
        solve(move + 1, nx1, ny1, nx2, ny2);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m;
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            board[i][j] = s[j];
            if (board[i][j] == 'o')
                coinPos.push_back(make_pair(i, j));
        }
    }
    solve(0, coinPos[0].first, coinPos[0].second, coinPos[1].first, coinPos[1].second);
    if (ans == 11)
        cout << -1;
    else
        cout << ans;
    return 0;
}