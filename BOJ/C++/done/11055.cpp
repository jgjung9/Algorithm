/**
 * https://www.acmicpc.net/problem/11055
 *
 * solution: 수열 A = {A1, A2, ...}
 * D[n]은 An이 마지막에 오는 부분증가 수열의 합의 최대 값이다.
 * D[n] = A[n] + max(D[i])  (i는 A[i] < A[n])
 */
#include <iostream>
#include <cmath>
using namespace std;
const int MAX_SIZE = 1001;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int a[MAX_SIZE];
    long long d[MAX_SIZE];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        d[i] = a[i];
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (a[i] > a[j])
                d[i] = max(d[i], a[i] + d[j]);
        }
    }
    long long answer = 0;
    for (int i = 1; i <= n; i++)
        answer = max(answer, d[i]);
    cout << answer;
    return 0;
}