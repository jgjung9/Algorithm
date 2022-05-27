/**
 * https://www.acmicpc.net/problem/2225
 *
 * hint: 0~N개의 정수 K개를 더해 합이 N이 되는 경우의 수
 * dp[n][k]를 k개를 써서 정수 n를 만드는 경우의 수라고 하자
 * 마지막에 선택하는 숫자가 i라 하면,
 * dp[n][k] = sigma(dp[n-i][k-1]) (0 <= i <= n);
 */
#include <iostream>
#include <vector>
using namespace std;
const int MAX_SIZE = 201;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    for (int i = 0; i <= n; i++)
        dp[i][1] = 1;
    for (int K = 2; K <= k; K++)
        for (int N = 0; N <= n; N++)
        {
            long long sum = 0;
            for (int i = 0; i <= N; i++)
                sum += dp[N - i][K - 1];
            dp[N][K] = sum % 1000000000;
        }
    cout << dp[n][k];
    return 0;
}