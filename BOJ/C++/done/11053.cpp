/**
 * https://www.acmicpc.net/problem/11053
 *
 * hint: DP를 활용한 LIS 풀이
 * 점화식 dp[i] 수열 a[i]에 주어진 값으로 끝나는 LIS의 최대길이로 두고 진행
 */
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int MAX_SIZE = 1000;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> dp(MAX_SIZE, 1);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (a[i] > a[j])
                dp[i] = max(dp[i], dp[j] + 1);

    int maxLen = 0;
    for (int i = 0; i < n; i++)
        maxLen = max(maxLen, dp[i]);
    cout << maxLen;
    return 0;
}