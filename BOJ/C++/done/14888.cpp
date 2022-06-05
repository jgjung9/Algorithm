/**
 * https://www.acmicpc.net/problem/14888
 *
 * solution:
 * 연산자중 하나를 선택하는 개념으로 문제를 풀 수 있다.
 */
#include <iostream>
using namespace std;
int n, pl, mi, mul, di;
int maxAns = -1e9, minAns = 1e9;
int number[11];

void go(int plus, int minus, int multiply, int divide, int value, int idx)
{
    if (plus > pl || minus > mi || multiply > mul || divide > di)
        return;
    if (idx == n)
    {
        maxAns = max(maxAns, value);
        minAns = min(minAns, value);
        return;
    }
    int next = number[idx];
    go(plus + 1, minus, multiply, divide, value + next, idx + 1);
    go(plus, minus + 1, multiply, divide, value - next, idx + 1);
    go(plus, minus, multiply + 1, divide, value * next, idx + 1);
    go(plus, minus, multiply, divide + 1, value / next, idx + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> number[i];
    cin >> pl >> mi >> mul >> di;
    go(0, 0, 0, 0, number[0], 1);
    cout << maxAns << '\n';
    cout << minAns << '\n';
    return 0;
}