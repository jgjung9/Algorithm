/**
 * https://www.acmicpc.net/problem/1309
 *
 * solution: 우리안에 사자를 가둔다고 할 때,
 * 사자를 왼쪽우리에 가두는 경우, 오른쪽 우리에 가두는 경우, 안 가두는 경우로 나눌 수 있다.
 * 사자를 왼쪽에 가둘경우 그 세로 한칸전 우리에는 사자가 없거나 혹은 오른쪽에 와야한다.
 * 오른쪽의 가둘 경우 왼쪽과 반대로 위치된다.
 * 안 가둘 경우 세로 한칸 전 우리에는 어떠한 모양이 와도 상관 없게 된다.
 * D[n][k] 를 세로 n칸의 우리에 사자를 가두는경우라고 할 때,
 * k = 0 사자를 안 가두는 경우
 * k = 1 사자를 왼쪽 k = 2 사자를 오른쪽
 * D[n][0] = D[n-1][0] + D[n-1][1] + D[n-1][2]
 * D[n][1] = D[n-1][0] + D[n-1][2]
 * D[n][2] = D[n-1][0] + D[n-1][1] 이 된다.
 */
#include <iostream>
#include <vector>
using namespace std;
const int MAX_SIZE = 100001;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int d[MAX_SIZE][3];
    d[1][0] = d[1][1] = d[1][2] = 1;
    for (int i = 2; i <= n; i++)
    {
        d[i][0] = (d[i - 1][0] + d[i - 1][1] + d[i - 1][2]) % 9901;
        d[i][1] = (d[i - 1][0] + d[i - 1][2]) % 9901;
        d[i][2] = (d[i - 1][0] + d[i - 1][1]) % 9901;
    }
    cout << (d[n][0] + d[n][1] + d[n][2]) % 9901;
    return 0;
}
