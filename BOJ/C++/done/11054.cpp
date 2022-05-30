/**
 * https://www.acmicpc.net/problem/11054
 *
 * solution: DP
 * 수열 A: {A1, A2, A3 ... An}
 * D[n]: An이 마지막에 오는 가장 긴 증가 부분 수열의 길이
 * D2[n]: An이 처음으로 오는 가장 긴 감소 부분 수열의 길이
 * D3[n]: n을 기점으로 전은 증가 후는 감소하는 바이토닉 부분수열의 가장 큰 길이
 * D[n]: max(D[i]) + 1 (i < n, A[i] < A[n] )
 * D2[n]: max(D2[i] + 1) (n < i, A[n] > A[i])
 * D3[n]: D[n] + D2[n] - 1
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
    cin >> n;
    vector<int> a(n + 1, 0);
    vector<int> d(n + 1, 1);
    vector<int> d2(n + 1, 1);
    vector<int> d3(n + 1, 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (a[j] < a[i])
                d[i] = max(d[i], d[j] + 1);
        }
    }

    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = n; j > i; j--)
        {
            if (a[i] > a[j])
                d2[i] = max(d2[i], d2[j] + 1);
        }
    }

    for (int i = 1; i <= n; i++)
        d3[i] = d[i] + d2[i] - 1;

    int answer = 0;
    for (int i = 1; i <= n; i++)
        answer = max(answer, d3[i]);

    cout << answer;
    return 0;
}
