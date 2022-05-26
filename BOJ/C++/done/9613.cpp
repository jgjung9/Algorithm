/**
 * https://www.acmicpc.net/problem/9613
 *
 * 모든 가능한 경우의 쌍을 돌며 gcd 값을 보관하고 이의 합을 출력한다.
 */
#include <iostream>
using namespace std;
const int MAX_INPUT = 100;

int GCD(int a, int b)
{
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        long long sum = 0;
        int n;
        cin >> n;
        int num[MAX_INPUT];
        for (int i = 0; i < n; i++)
            cin >> num[i];

        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
                sum += GCD(num[i], num[j]);

        cout << sum << '\n';
    }
    return 0;
}