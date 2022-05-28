/**
 * https://www.acmicpc.net/problem/9465
 *
 * solution: 마지막 열 스티커를 위, 아래, 안떼는 경우로 나눌 수 있다.
 * D[k][n] (k = 0 안떼는 경우, k = 1 위, k = 2 아래)를 n행까지 진행 했을 때 최대라고 하면,
 * D[0][n] = max(D[0~2][n-1])
 * D[1][n] = max(D[2][n-1]+A[0][n], D[0][n-1]+A[0][n])
 * D[2][n] = max(D[1][n-1]+A[1][n], D[1][n-1]+A[1][n])으로 볼 수 있다.
 */
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> a(2, vector<int>(n + 1, 0));
        vector<vector<int>> d(3, vector<int>(n + 1, 0));
        for (int i = 0; i < 2; i++)
            for (int j = 1; j <= n; j++)
                cin >> a[i][j];
        d[0][1] = 0, d[1][1] = a[0][1], d[2][1] = a[1][1];
        for (int i = 2; i <= n; i++)
        {
            d[0][i] = max(max(d[0][i - 1], d[1][i - 1]), d[2][i - 1]);
            d[1][i] = max(d[2][i - 1], d[0][i - 1]) + a[0][i];
            d[2][i] = max(d[0][i - 1], d[1][i - 1]) + a[1][i];
        }

        int answer = 0;
        for (int i = 0; i < 3; i++)
            answer = max(answer, d[i][n]);
        cout << answer << '\n';
    }
    return 0;
}