/**
 * https://www.acmicpc.net/problem/2156
 *
 * solution: 연속으로 3번 마시지 못하므로
 * 마지막에 마실 경우 직전 포도주를 마신 경우와 마시지 않은 경우로 나눌 수 있다.
 * n 번째 포도주의 양을 A(n) 이라 하고, n번째까지 지나왔을 때 가장 많이 먹은양을 D(n)이라 하면,
 * 직전 잔을 마신 경우 D(n) = A(n-1) + A(n) + D(n-3)
 * 직전 잔을 마시지 않은 경우 D(n) = D(n-2) + A(n)이다.
 * 또한 n 번째 포도주를 먹지 않는 경우도 존재한다. D(n) = D(n-1)
 * 따라서 D(n)은 위 두 경우의 중에 큰 값이 된다.
 */
#include <iostream>
#include <cmath>
using namespace std;
const int MAX_SIZE = 10000;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    int a[MAX_SIZE];
    int d[MAX_SIZE];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    d[0] = a[0];
    d[1] = a[0] + a[1];
    d[2] = max(max(d[0] + a[2], a[1] + a[2]), d[1]);
    for (int i = 3; i < n; i++)
        d[i] = max(max(d[i - 2] + a[i], d[i - 3] + a[i] + a[i - 1]), d[i - 1]);

    cout << d[n - 1];
    return 0;
}