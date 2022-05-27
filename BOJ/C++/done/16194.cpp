/**
 * https://www.acmicpc.net/problem/16194
 *
 * hint: DP를 이용해 최솟값을 찾아간다.
 * dp[n] = min(dp[n - i] + p[i]);
 */
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
const int MAX_SIZE = 1001;

int main()
{
    vector<int> dp(MAX_SIZE, -1);

    int n;
    cin >> n;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
        dp[i] = p[i];
    }

    for (int i = 2; i <= n; i++)
        for (int j = 1; j < i; j++)
            dp[i] = min(dp[i], dp[i - j] + p[j]);

    cout << dp[n];
    return 0;
}