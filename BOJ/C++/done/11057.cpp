/**
 * https://www.acmicpc.net/problem/11057
 *
 * solution: DP
 * 마지막에 오는 수가 K라고 할 때,
 * D(n)(k) = sigma(D(n-1)(i)) (i <= k)
 * D(1)(i) = 1 (i = 0 ~ 9)
 */
#include <iostream>
using namespace std;
const int mod = 10007;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int d[1001][10] = {0};
    for (int i = 0; i < 10; i++)
        d[1][i] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k <= j; k++)
            {
                d[i][j] += d[i - 1][k] % mod;
            }
            d[i][j] %= mod;
        }
    }

    int answer = 0;
    for (int i = 0; i < 10; i++)
        answer += d[n][i];
    cout << answer % mod;
    return 0;
}