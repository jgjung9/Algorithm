/**
 * https://www.acmicpc.net/problem/2193
 *
 * hint: 마지막에 0이 오는 경우와 마지막에 1이 오는 경우
 * 두가지로 나눠 생각 할 수 있고, 따라서 DP를 사용할 수 있다.
 * n자리 이친수에서 마지막에 0이 오는 것은 앞에 어떤 값이 와도 생각없으므로
 * d[n - 1] 이 되고, 마지막에 1이 오는 경우는 앞에 0이 와야 하고
 * 그 앞에 0, 1 둘다 올 수 있으므로 dp[n] = d[n - 1] + d[n - 2]이 된다
 */
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> dp(n + 1, 0);
    dp[1] = dp[2] = 1;

    for (int i = 3; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    cout << dp[n];
    return 0;
}