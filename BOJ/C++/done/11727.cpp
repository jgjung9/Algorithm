/**
 * https://www.acmicpc.net/problem/11727
 *
 * hint: DP를 활용해 문제를 해결할 수 있다.
 * 마지막에 놓는 타일이 | ㅡ ㅁ 에 따라서 경우를 나눌 수 있다.
 * | 놓는 경우는 dp[n - 1] ㅡ 놓는 경우 dp[n - 2] ㅁ 놓는 경우 dp[n - 2]이다.
 * 따라서 dp[n] = dp[n - 1] + 2 * dp[n - 2]이다.
 */
#include <iostream>
using namespace std;
const int MAX_SIZE = 1001;

int main()
{
    int dp[MAX_SIZE];
    dp[1] = 1;
    dp[2] = 3;
    int n;
    cin >> n;
    for (int i = 3; i <= n; i++)
        dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % 10007;

    cout << dp[n];
    return 0;
}