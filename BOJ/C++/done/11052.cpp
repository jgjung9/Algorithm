/**
 * https://www.acmicpc.net/problem/11052
 *
 * hint: DP를 활용해 해결 할 수 있다.
 * 마지막에 구매하는 카드 팩에 따라서 경우를 나눌 수 있다.
 * Pi를 마지막에 구매한다고 했을 때 dp[n] = dp[n-i] + Pi된다.
 * 따라서 N를 구매했을 때 쓰는 비용이 최대가 되려면,
 * dp[n] = max(dp[n-i] + Pi) (i = 1 ~ n) 이 된다.
 */
#include <iostream>
#include <cmath>
using namespace std;
const int MAX_SIZE = 1001;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    int p[MAX_SIZE];
    int dp[MAX_SIZE];
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    dp[1] = p[1];
    for (int i = 2; i <= n; i++)
    {
        dp[i] = p[i];
        for (int j = 1; j < i; j++)
            dp[i] = max(dp[j] + p[i - j], dp[i]);
    }
    cout << dp[n];
    return 0;
}