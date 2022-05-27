/**
 * https://www.acmicpc.net/problem/10844
 *
 * hint: 계단수의 시작은 1로 진행한다.
 * 계단수에 올 수 있는 수는 0~9 까지만이다.
 * 마지막에 오는 숫자에 따라 케이스를 나눌 수 있다.
 * n자리의 계단수 중 마지막에 숫자 i 가 오는 경우의 수를 dp[n][i] 라고 할 때,
 * dp[n][i] = dp[n -1][i -1] + dp[n - 1][i + 1]이 된다.
 * 또한 i = 0, i = 9일때는 앞 숫자는 1과 8만 올 수 있으므로 해당 부분 예외처리를 진행한다.
 */
#include <iostream>
using namespace std;
const int MAX_SIZE = 101;
const int NUM_SIZE = 10;

int main()
{
    int dp[MAX_SIZE][NUM_SIZE] = {0};
    for (int i = 1; i < NUM_SIZE; i++)
        dp[1][i] = 1;
    int n;
    cin >> n;
    for (int i = 2; i < MAX_SIZE; i++)
        for (int j = 0; j < NUM_SIZE; j++)
        {
            if (j == 0)
                dp[i][j] = dp[i - 1][j + 1] % 1000000000;
            else if (j == 9)
                dp[i][j] = dp[i - 1][j - 1] % 1000000000;
            else
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
        }

    long long answer = 0;
    for (int i = 0; i <= 9; i++)
        answer += dp[n][i];

    cout << answer % 1000000000;
    return 0;
}