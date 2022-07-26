/**
 * https://www.acmicpc.net/problem/1890
 *
 * solution: DP
 */
#include <iostream>
using namespace std;
int n;
int board[100][100];
const int dx[] = {0, 1};
const int dy[] = {1, 0};
long long d[100][100];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];
    d[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 0)
                continue;
            for (int dir = 0; dir < 2; dir++)
            {
                int nx = i + board[i][j] * dx[dir];
                int ny = j + board[i][j] * dy[dir];
                if (nx > n || ny > n)
                    continue;
                d[nx][ny] += d[i][j];
            }
        }
    }
    cout << d[n - 1][n - 1];
    return 0;
}