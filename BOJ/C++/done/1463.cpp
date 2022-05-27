/**
 * https://www.acmicpc.net/problem/1463
 *
 * hint: DP를 활용하여 해결가능
 * Dp[n] = Dp[n/3] + 1 or Dp[n/2] + 1 or Dp[n-1] + 1이 된다
 * 이 중에서 가능 작은 값이 답이 된다.
 */
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int MAX_SIZE = 1000001;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> dp(MAX_SIZE, 0);
    dp[2] = dp[3] = 1;
    int n;
    cin >> n;
    for (int i = 4; i <= n; i++)
    {
        if (i % 3 == 0 && i % 2 == 0)
            dp[i] = min(min(dp[i / 3], dp[i / 2]), dp[i - 1]) + 1;
        else if (i % 3 == 0)
            dp[i] = min(dp[i / 3], dp[i - 1]) + 1;
        else if (i % 2 == 0)
            dp[i] = min(dp[i / 2], dp[i - 1]) + 1;
        else
            dp[i] = dp[i - 1] + 1;
    }
    cout << dp[n];
    return 0;
}