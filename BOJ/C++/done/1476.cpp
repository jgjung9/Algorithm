/**
 * https://www.acmicpc.net/problem/1476
 *
 * solution: E S M 을 모듈러 연산을 통해 구할 수 있다.
 */
#include <iostream>
using namespace std;

int main()
{
    int E, S, M;
    cin >> E >> S >> M;
    int e, s, m;
    for (int i = 1;; i++)
    {
        e = (i - 1) % 15 + 1;
        s = (i - 1) % 28 + 1;
        m = (i - 1) % 19 + 1;
        if (e == E && s == S && m == M)
        {
            cout << i;
            break;
        }
    }
    return 0;
}