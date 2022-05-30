/**
 * https://www.acmicpc.net/problem/1748
 *
 * solution: 단순히 계산하게 될 경우 시간초과가 된다.
 * 자릿수가 커지는 만큼 1씩 더해준다.
 * ex) 95의 경우 모든 1자리 이상이므로 일단 1을 더해준다
 * 2자리 이상의 경우는 10 ~ 95 이므로 95 - 10 + 1이다.
 * 따라서 95 - 10 + 1만큼 더할 수 있다.
 * 이 보다 큰 수도 동일한 방식으로 처리 할 수 있다.
 */
#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int answer = 0;
    for (int i = 1; i <= n; i *= 10)
        answer += n - i + 1;
    cout << answer;
    return 0;
}
