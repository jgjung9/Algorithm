/**
 * https://www.acmicpc.net/problem/22941
 *
 * solution: 단순 구현 + 수학
 */
#include <iostream>
using namespace std;

int main()
{
    long long uh, ua, dh, da, p, s;
    cin >> uh >> ua >> dh >> da >> p >> s;
    long long trigger = dh - p;

    // 회복을 안쓸 경우 마왕을 죽이는데 필요한 공격횟수와
    // 회복을 쓰는 트리거에 해당하는 피에 도달하는데 필요한 공격횟수를 비교해서
    // 죽이는데 필요한 공격횟수가 트리거의 공격횟수보다 많을 경우
    // 마왕은 체력을 회복한다.
    // 따라서 마왕의 체력에 s를 더한후 죽이는데 필요한 횟수를 다시 구해준다.
    long long uAtkCnt = dh % ua == 0 ? dh / ua : dh / ua + 1;
    long long preUserAtkCnt = trigger % ua == 0 ? trigger / ua : trigger / ua + 1;
    if (uAtkCnt > preUserAtkCnt)
    {
        dh += s;
        uAtkCnt = dh % ua == 0 ? dh / ua : dh / ua + 1;
    }

    long long dAtkCnt = uh % da == 0 ? uh / da : uh / da + 1;
    if (uAtkCnt <= dAtkCnt)
        cout << "Victory!";
    else
        cout << "gg";
    return 0;
}
