/**
 * https://www.acmicpc.net/problem/1149
 *
 * solution: 빨 0 초 1 파 2
 * D[k][n] n번째 집을 마지막으로 칠하고 색이 k(0~2)인 최소비용
 * D[k][n] = min(D[i][n-1]) + A[k][n] (i = 0~2, 단 k를 제외한)
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
    int a[3][MAX_SIZE];
    int d[3][MAX_SIZE];
    for (int i = 1; i <= n; i++)
        cin >> a[0][i] >> a[1][i] >> a[2][i];
    d[0][1] = a[0][1], d[1][1] = a[1][1], d[2][1] = a[2][1];
    for (int i = 2; i <= n; i++)
    {
        d[0][i] = min(d[1][i - 1], d[2][i - 1]) + a[0][i];
        d[1][i] = min(d[0][i - 1], d[2][i - 1]) + a[1][i];
        d[2][i] = min(d[0][i - 1], d[1][i - 1]) + a[2][i];
    }
    cout << min(min(d[0][n], d[1][n]), d[2][n]);
    return 0;
}
