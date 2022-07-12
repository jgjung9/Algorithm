/**
 * https://www.acmicpc.net/problem/16198
 *
 * solution: Brute Force (Backtracking)
 * 처음과 마지막을 제외한 모든 구슬을
 * 가능한 모든 방식으로 제거하고 그 결과의 최댓값을 구한다.
 */
#include <iostream>
using namespace std;
int n, ans = 0;
int w[10];
bool removed[10];

void solve(int cnt, int res)
{
    if (cnt == n - 2)
    {
        ans = max(ans, res);
        return;
    }

    for (int i = 1; i < n - 1; i++)
    {
        if (removed[i])
            continue;

        removed[i] = true;
        int lp = i - 1;
        int rp = i + 1;
        while (removed[lp])
            lp--;
        while (removed[rp])
            rp++;
        solve(cnt + 1, res + w[lp] * w[rp]);
        removed[i] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> w[i];
    solve(0, 0);
    cout << ans;
    return 0;
}