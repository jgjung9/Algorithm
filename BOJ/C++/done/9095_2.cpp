/**
 * https://www.acmicpc.net/problem/9095
 *
 * DP를 사용하지 않고 재귀적인 풀이
 */
#include <iostream>
using namespace std;

int Count(int sum, int goal)
{
    if (sum > goal)
        return 0;
    if (sum == goal)
        return 1;
    int cnt = 0;
    for (int i = 1; i <= 3; i++)
        cnt += Count(sum + i, goal);
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, n, ans;
    cin >> t;
    while (t--)
    {
        cin >> n;
        ans = Count(0, n);
        cout << ans << '\n';
    }
    return 0;
}