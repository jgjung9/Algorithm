/**
 * https://www.acmicpc.net/problem/13398
 *
 * solution: DP
 * 수열 A {A1, A2, ... An}
 * D[n]: An이 마지막에 오는 연속합의 최대 값
 * D[n] = D(n - 1) + An (D(n-1) > 0) or An (D(n-1) < 0)
 * D2[n] : An이 처음에 오는 연속합의 최대 값
 * D2[n] = D2(n + 1) + An (D2(n+1) > 0) or D2[n] = An (D2[n+1] < 0)
 * k을 제거했을 때 최대 값은 : D[k -1] + D2[k + 1]이 된다
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    vector<int> d(n + 1, 0);
    vector<int> d2(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        d[i] = a[i];
        d2[i] = a[i];
    }

    for (int i = 2; i <= n; i++)
    {
        if (d[i - 1] >= 0)
            d[i] = d[i - 1] + a[i];
    }

    for (int i = n - 1; i >= 1; i--)
    {
        if (d2[i + 1] >= 0)
            d2[i] = d2[i + 1] + a[i];
    }

    int answer = -1000;
    for (int i = 1; i <= n; i++)
        answer = max(answer, d[i]);

    for (int i = 2; i <= n - 1; i++)
        answer = max(answer, d[i - 1] + d2[i + 1]);

    cout << answer;
    return 0;
}