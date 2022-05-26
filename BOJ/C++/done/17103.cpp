/**
 * https://www.acmicpc.net/problem/17103
 *
 * 골드바흐 추측을 해결하기 위해 에라토스테네스의 체를 이용하여
 * 소수판정을 진행하고 n = left + right (n은 2이상의 짝수 left, right는 소수)
 * left < n/2 일 때 right < n/2이면 left + right < n 이므로
 * left <= n/2 일 때 까지만 카운트를 진행한다.
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
        for (int j = i + i; j < MAX_SIZE; j += i)
            isPrime[j] = false;

    int t;
    cin >> t;
    while (t--)
    {
        int count = 0;
        int n;
        cin >> n;
        for (int i = 2; i <= n / 2; i++)
            if (isPrime[i] && isPrime[n - i])
                count++;
        cout << count << '\n';
    }
    return 0;
}