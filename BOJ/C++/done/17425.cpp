/**
 * https://www.acmicpc.net/problem/17425
 *
 * solution: g(x) = g(x - 1) + f(x)
 * 1~N까지의 수들의 자신의 약수의 합을
 * i = 1 ~ N 까지 i의 배수들에 i를 더해주는 방식으로 구현하면
 * i 마다 N/i 번의 호출을 하게된다.
 * 따라서 N/1 + N/2 + N/3 + ... N/(N-1) + 1의 연산을 진행하게 되고
 * 이는 N(1 + 1/2 + 1/3 + 1/4 +  ....) 으로 나타낼수 있다.
 * 이것은(i = 1 -> n)갈 때, 시그마(1/i) 이므로 적분을 할 수 있게 된다.
 * 적분을 하면 lnN이므로 N * (lnN)의 연산이 진행된다.
 * 따라서 O(nlogn)의 시간 복잡도를 가지는 연산이다.
 * 따라서 총 시간 복잡도는 O(nlogn + n + t)이므로 O(nlogn)으로 볼 수 있다.
 * n <= 10^6 이므로 6*1e6 < 1e8 이므로 시간초과를 해결할 수 있다.
 */
#include <iostream>
#include <vector>
using namespace std;
const int MAX_SIZE = 1e6 + 1;
vector<int> f(MAX_SIZE, 1);
vector<long long> g(MAX_SIZE, 1);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 2; i < MAX_SIZE; i++)
    {
        for (int j = 1; j * i < MAX_SIZE; j++)
            f[j * i] += i;
        g[i] = g[i - 1] + f[i];
    }
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << g[n] << '\n';
    }
    return 0;
}