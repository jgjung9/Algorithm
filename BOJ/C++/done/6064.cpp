/**
 * https://www.acmicpc.net/problem/6064
 *
 * solution: 카잉 달력의 주기는 M, N의 최소 공배수와 동일하다
 * 최소 공배수 + 1 = <1 : 1> 이 되므로 체크 해줘야 하는 최대 년도는
 * LCM(M, N)이 된다
 * 또한 카잉 달력에서 <x:y> x의 값은 M마다 반복되고 y의 값은 N 마다 반복된다.
 * 따라서 처음 들어온 x, y 값을 시작 점으로 정하고 x를 기준으로 할 경우
 * 매 번 M를 더해 입력된 y값이 나오는지 LCM(M, N)까지 확인 한다.
 * y를 기준으로 할 경우 매번 N씩 더해 x 값이 나오는지 확인하면 된다.
 */
#include <iostream>
using namespace std;

int GCD(int a, int b)
{
    if (b == 0)
        return a;
    while (b > 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int LCM(int a, int b)
{
    return a * b / GCD(a, b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    int answer = 0;
    cin >> t;
    while (t--)
    {
        int M, N, x, y;
        cin >> M >> N >> x >> y;
        int cycle = LCM(M, N);
        int answer = -1;
        for (int i = x; i <= cycle; i += M)
        {
            if ((i - 1) % N + 1 == y)
            {
                answer = i;
                break;
            }
        }
        cout << answer << '\n';
    }
    return 0;
}
