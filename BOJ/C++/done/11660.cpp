#include <iostream>
using namespace std;
int n, m, x1, x2, y1, y2;
int board[1025][1025];
int sum[1025][1025] = {0};
int ans = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> board[i][j];
            sum[i][j] += sum[i][j - 1] + board[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        ans = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = x1; i <= x2; i++)
            ans += sum[i][y2] - sum[i][y1 - 1];
        cout << ans << '\n';
    }
    return 0;
}