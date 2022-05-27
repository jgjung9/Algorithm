/**
 * https://www.acmicpc.net/problem/1699
 *
 * hint: d[n]은 제곱수로 n을 만들 때 최소 항의 개수라고 하자
 * n을 만드는데 사용 될 수 있는 제곱수 s1 s2 ... 라고 할 때,
 * 마지막에 s1이 올 때 최소 경우의 수는 dp[n-s1] + 1이 된다.
 * 따라서 dp[n] = min(dp[n-si]) + 1이다.
 */
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int MAX_SIZE = 100001;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> dp(MAX_SIZE);
    for (int i = 1; i <= n; i++)
    {
        dp[i] = i;
        for (int j = 1; j * j <= i; j++)
            dp[i] = min(dp[i], dp[i - (j * j)] + 1);
    }
    cout << dp[n];
    return 0;
}