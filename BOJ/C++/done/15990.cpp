/**
 * https://www.acmicpc.net/problem/15990
 *
 * hint: 같은 수를 연속해서 등장불가로 2차원 배열 DP로 진행가능하다.
 * 마지막에 1, 2, 3이 오는 경우로 케이스를 나눌 수 있다.
 * 마지막에 오는 수가 i일 때 올 수 있는 경우의 수를 dp[n][i]이라 하면,
 * dp[n][1] = dp[n-1][2] + dp[n-1][3]
 * dp[n][2] = dp[n-2][1] + dp[n-2][3]
 * dp[n][3] = dp[n-3][1] + dp[n-3][2] 가 된다.
 */
#include <iostream>
using namespace std;
const int MAX_SIZE = 100001;
const int CASE_SIZE = 4;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int dp[MAX_SIZE][CASE_SIZE] = {0};
    dp[1][1] = 1, dp[1][2] = dp[1][3] = 0;
    dp[2][2] = 1, dp[2][1] = dp[2][3] = 0;
    dp[3][1] = dp[3][2] = dp[3][3] = 1;

    for (int i = 4; i < MAX_SIZE; i++)
        for (int j = 1; j < CASE_SIZE; j++)
        {
            if (j == 1)
                dp[i][j] = (dp[i - 1][2] + dp[i - 1][3]) % 1000000009;
            else if (j == 2)
                dp[i][j] = (dp[i - 2][1] + dp[i - 2][3]) % 1000000009;
            else
                dp[i][j] = (dp[i - 3][1] + dp[i - 3][2]) % 1000000009;
        }

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        long long answer = 0;
        for (int i = 1; i < CASE_SIZE; i++)
            answer += dp[n][i];
        cout << answer % 1000000009 << '\n';
    }
    return 0;
}