/**
 * https://www.acmicpc.net/problem/17087
 *
 * hint: 수빈이의 위치에서 D의 거리로 앞 뒤로 움직일 수 있으므로
 * 수빈이가 갈 수 있는 위치는 S + Dn (n은 정수) 이다
 * 따라서 A1 ~ AN 은 모두 S + Dn  집합에 속해 있어야 한다.
 * Ai - S = Dn이고 이때 n을 n1이라 하면,
 * Dn1 Dn2 Dn3 ... DnN => 모두 D가 공통적으로 있으므로
 * D의 최대값은 결국 Dn1 Dn2 Dn3 ... DnN의 최대 공약수가 된다.
 */
#include <iostream>
#include <cmath>
using namespace std;

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
    int gcd = 0;
    int n, s;
    cin >> n >> s;
    while (n--)
    {
        int a;
        cin >> a;
        int distance = abs(s - a);
        gcd = GCD(distance, gcd);
    }
    cout << gcd;
    return 0;
}