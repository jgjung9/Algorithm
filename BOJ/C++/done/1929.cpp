/**
 * https://www.acmicpc.net/problem/1929
 *
 * hint: 범위의 소수를 구하는 최적의 알고리즘은
 * 에라토스테네스의 체로 이를 활용한다.
 */
#include <iostream>
#include <cstring>
using namespace std;
const int MAX_SIZE = 1000001;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, n;
    cin >> m >> n;
    bool isPrime[MAX_SIZE];
    memset(isPrime, true, MAX_SIZE);
    isPrime[0] = false;
    isPrime[1] = false;

    for (int i = 2; i <= n; i++)
        for (int j = i + i; j <= n; j += i)
            isPrime[j] = false;

    for (int i = m; i <= n; i++)
        if (isPrime[i])
            cout << i << '\n';

    return 0;
}