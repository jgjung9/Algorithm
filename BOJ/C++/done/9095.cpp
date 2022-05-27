/**
 * https://www.acmicpc.net/problem/9095
 *
 * hint: DP를 활용해 해결할 수 있다.
 * 1 + 1 + 2 , 1 + 2 + 1 이 다른 것으로 판별하므로
 * 마지막에 오는 숫자를 기준을 경우를 나눌 수 있다.
 * 따라서 마지막 숫자가 1 인 경우 dp[n - 1]
 * 2인 경우 dp[n - 2]
 * 3인 경우 dp[n - 3] 이 된다
 * 따라서 dp[n] = dp[n-1] + dp[n-2] + dp[n-3]으로 볼 수 있다.
 */
#include <iostream>
using namespace std;
const int MAX_SIZE = 11;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int dp[MAX_SIZE];
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i < 11; i++)
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }
    return 0;
}