/**
 * https://www.acmicpc.net/problem/15988
 *
 * solution: 마지막에 오는 수가 1, 2, 3 어떤 것인지에 따라 나눌 수 있따.
 * D(n)을 n 을 1, 2, 3의 합으로 나타낼 수 있는 개수라고 할 때,
 * 마지막에 1이 오는 경우는 D(n - 1)
 * 마지막에 2이 오는 경우는 D(n - 2)
 * 마지막에 3이 오는 경우는 D(n - 3)
 * 따라서 D(n) = D(n - 1) + D(n - 2) + D(n - 3)이 된다.
 */
#include <iostream>
#include <vector>
using namespace std;
const int MAX_SIZE = 1000001;
const int modular = 1000000009;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    vector<long long> d(MAX_SIZE, 0);
    d[1] = 1, d[2] = 2, d[3] = 4;
    for (int i = 4; i < MAX_SIZE; i++)
        d[i] = (d[i - 1] + d[i - 2] + d[i - 3]) % modular;
    while (t--)
    {
        int n;
        cin >> n;
        cout << d[n] << '\n';
    }

    return 0;
}