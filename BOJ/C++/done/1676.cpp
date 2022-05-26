/**
 * https://www.acmicpc.net/problem/1676
 *
 * hint: factorial에서 0이 나오기 위해서는 10을 인수로 가져야 한다.
 * 10 = 2x5 이고 factorial에서 2의 개수를 5의 개수보다 무조건 많을 수 밖에 없다
 * 따라서 0의 개수는 5의 개수가 된다.
 */

#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int count = 0;
    count += n / 5;
    count += n / 25;
    count += n / 125;
    cout << count;

    return 0;
}