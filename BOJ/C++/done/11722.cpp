/**
 * https://www.acmicpc.net/problem/11722
 *
 * solution: DP
 * 수열 A = {A1, A2, A3, ... An}
 * D[n] = An이 마지막에 오는 가장 긴 감소 수열의 길이
 * D[n] = max(D(k)) + 1 (An < Ak)
 */
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    int a[1001];
    vector<int> d(1001, 1);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (a[j] > a[i])
                d[i] = max(d[i], d[j] + 1);
        }
    }

    int answer = 0;
    for (int i = 1; i <= n; i++)
        answer = max(answer, d[i]);
    cout << answer;
    return 0;
}