/**
 * https://www.acmicpc.net/problem/1182
 *
 * solution: 비트마스크를 이용한 풀이
 */
#include <iostream>
using namespace std;
int n, s, ans = 0, seq[20];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cin >> seq[i];

    for (int i = 1; i < (1 << n); i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
                sum += seq[j];
        }
        if (sum == s)
            ans++;
    }
    cout << ans;
    return 0;
}