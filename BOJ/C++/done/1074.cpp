/**
 * https://www.acmicpc.net/problem/1074
 *
 * solution: 분할정복
 */
#include <iostream>
using namespace std;
int n, r, c, ans, length = 1;

void divide(int targetX, int targetY, int length, int count)
{

    if (length == 1)
    {
        ans = count;
        return;
    }

    int q = length / 2;
    int squre = q * q;

    if (targetX < q)
    {
        if (targetY < q)
            divide(targetX, targetY, q, count);
        else
            divide(targetX, targetY - q, q, count + squre);
    }
    else
    {
        if (targetY < q)
            divide(targetX - q, targetY, q, count + 2 * squre);
        else
            divide(targetX - q, targetY - q, q, count + 3 * squre);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> r >> c;
    for (int i = 0; i < n; i++)
        length *= 2;
    divide(r, c, length, 0);
    cout << ans;
    return 0;
}