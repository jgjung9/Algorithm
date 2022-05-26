/**
 * https://www.acmicpc.net/problem/6588
 *
 * hint: 골드바흐 추측은 4보다 큰 짝수는 두 홀수 소수의 합으로 나타낼 수 있다는 추측으로
 * 에레토스테네스의 체를 이용해 주어진 범위의 모든 소수를 구한 후
 * n = left + right (n >= 4, n은 짝수, left and right are prime number)
 * 3 ~ n/2 까지의 소수를 left 자리에 차례대로 하나씩 넣고 n - left 값도 소수 인지 확인한다.
 * 만족하는 경우가 처음 등장하면 n = left + right를 출력하고 다음 케이스로 넘어간다.
 */
#include <iostream>
#include <cstring>
using namespace std;
const int MAX_SIZE = 1000001;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    bool isPrime[MAX_SIZE];
    memset(isPrime, true, MAX_SIZE);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i < MAX_SIZE; i++)
    {
        if (!isPrime[i])
            continue;
        for (int j = i + i; j < MAX_SIZE; j += i)
            isPrime[j] = false;
    }

    while (true)
    {
        int n;
        cin >> n;
        if (n == 0)
            break;

        for (int i = 3; i <= n / 2; i++)
            if (isPrime[i] && isPrime[n - i])
            {
                cout << n << " = " << i << " + " << n - i << '\n';
                break;
            }
    }

    return 0;
}