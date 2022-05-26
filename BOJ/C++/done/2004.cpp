/**
 * https://www.acmicpc.net/problem/2004
 *
 * hint: factorial에서 0의 개수는 10개수로 10의 개수를 카운팅한다.
 * 이를 조합에서도 똑같이 활용해 진행한다.
 *
 * 10 = 2x5
 * nCm = n! / ((n-m)! * m!)
 * n!의 2의 개수 - (n-m)!의 2의 개수 - m!의 2의 개수
 * n!의 5의 개수 - (n-m)!의 5의 개수 - m!의 5의 개수 를 구한다.
 * 남아 있는 2와 5의 개수중에 작은 값의 수 만큼 10을 만들 수 있다.
 */
#include <iostream>
#include <algorithm>
using namespace std;

int twoCountInFactorial(int n)
{
    int count = 0;
    for (long long i = 2; i <= n; i = i * 2)
        count += n / i;
    return count;
}

int fiveCountInFactorial(int n)
{
    int count = 0;
    for (long long i = 5; i <= n; i = i * 5)
        count += n / i;
    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    int twoCount = twoCountInFactorial(n) - twoCountInFactorial(m) - twoCountInFactorial(n - m);
    int fiveCount = fiveCountInFactorial(n) - fiveCountInFactorial(m) - fiveCountInFactorial(n - m);
    cout << min(twoCount, fiveCount);

    return 0;
}