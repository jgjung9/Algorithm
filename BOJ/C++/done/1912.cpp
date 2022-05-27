/**
 * https://www.acmicpc.net/problem/1912
 *
 * hint: 임의로 연속된 수를 골라 구할 수 있는 합중 최대가 되는 경우
 * 수열 S : s1 s2 s3 ... sn
 * si를 연속된 수중 마지막으로 하는 값중 가장 큰값을 di라
 * d(i-1)이 음수가 아닌 이상 d(i-1) 에 si를 더해준 값이 di가 된다.
 * di = d(i-1) + si (d(i-1) > 0) or di = si (di(i-1) < 0)
 */
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> seq(n);
    vector<int> dp(n);
    for (int i = 0; i < n; i++)
        cin >> seq[i];

    dp[0] = seq[0];
    for (int i = 1; i < n; i++)
    {
        if (dp[i - 1] < 0)
            dp[i] = seq[i];
        else
            dp[i] = dp[i - 1] + seq[i];
    }
    int maxSum = -1000;
    for (int i = 0; i < n; i++)
        maxSum = max(maxSum, dp[i]);
    cout << maxSum;
    return 0;
}