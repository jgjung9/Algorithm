/**
 * https://www.acmicpc.net/problem/9656
 *
 * solution: 1 + 1, 1 + 3, 3 + 1, 3 + 3 은 모두 짝수이다.
 * 즉, 처음 두는 사람은 무조건 홀수를 만들고 두번째로 두는 사람은 무조건 짝수를 만들게 된다.
 * 따라서, 짝수가 나온다면 첫번째 턴인 SK가 이기고 홀수가 나온다면 두번째 턴인 CY가 이기게 된다.
 */
#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;

    if (n % 2 == 0)
        cout << "SK";
    else
        cout << "CY";
    return 0;
}