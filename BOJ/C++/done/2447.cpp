/**
 * https://www.acmicpc.net/problem/2447
 *
 * solution: 분할정복
 */
#include <iostream>
using namespace std;
int n;

void divide(int r, int c, int x, int y, int len)
{
    if (len == 1)
    {
        cout << '*';
        return;
    }

    len = len / 3;
    if (x < r + len && y < c + len)
        divide(r, c, x, y, len);
    else if (x < r + len && y >= c + len && y < c + 2 * len)
        divide(r, c + len, x, y, len);
    else if (x < r + len && y >= c + 2 * len)
        divide(r, c + 2 * len, x, y, len);
    else if (x < r + 2 * len && y < c + len)
        divide(r + len, c, x, y, len);
    else if (x < r + 2 * len && y >= c + len && y < c + 2 * len)
        cout << ' ';
    else if (x < r + 2 * len && y >= c + 2 * len)
        divide(r + len, c + 2 * len, x, y, len);
    else if (y < c + len)
        divide(r + 2 * len, c, x, y, len);
    else if (y >= c + len && y < c + 2 * len)
        divide(r + 2 * len, c + len, x, y, len);
    else
        divide(r + 2 * len, c + 2 * len, x, y, len);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            divide(0, 0, i, j, n);
        cout << '\n';
    }
    return 0;
}