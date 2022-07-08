/**
 * https://www.acmicpc.net/problem/10986
 *
 * solution: 모듈러 연산의 특성을 이용한 문제
 * 어떠한 값 s1, s2, m 이 주어질 때 (s1 > s2)
 * (s1 - s2) % m = 0 가 성립하기 위해서는
 * s1 % m == s2 % m 이어야 한다.
 * 1 ~ n 까지의 합의 % m 값을 기록하고 나머지가 동일한 것을 2개 골라
 * 구간을 만들어 준다고 생각할 수 있다.
 * 나머지가 0 일 경우에는 자신도 개수에 포함시켜준다.
 */
#include <iostream>
using namespace std;
using ll = long long;
ll ans, sum[1000001] = {0};
int remain[1000] = {0};
int n, m, a;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m;

    remain[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        sum[i] = sum[i - 1] + a;
        remain[sum[i] % m]++;
    }

    for (int i = 0; i < m; i++)
        ans += static_cast<ll>(remain[i]) * (remain[i] - 1) / 2;

    cout << ans;
    return 0;
}