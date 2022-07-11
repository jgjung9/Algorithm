/**
 * https://www.acmicpc.net/problem/4811
 *
 * D[n][k] = n일차 k개의 온전한 알약을 먹었음 (n - k)개의 반개의 알약을 먹음
 * k >= n - k 여야만함 즉 k >= n/2
 * k < n / 2 인 경우는 존재하지 않음
 * k == n/2 --> n 이 짝수인 경우에만 가능
 * D[n][k] = D[n - 1][k];
 * k > n / 2
 * D[n][k] = D[n - 1][k - 1] + D[n - 1][k]
 */
#include <iostream>
using namespace std;
int n;
long long D[61][61] = {0};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    for (int i = 1; i <= 60; i++)
        D[i][i] = 1;
    for (int i = 2; i <= 60; i++)
    {
        if (i % 2 == 0)
            D[i][i / 2] = D[i - 1][i / 2];

        for (int j = i / 2 + 1; j < i; j++)
            D[i][j] = D[i - 1][j] + D[i - 1][j - 1];
    }

    while (true)
    {
        cin >> n;
        if (n == 0)
            break;
        cout << D[2 * n][n] << '\n';
    }
    return 0;
}