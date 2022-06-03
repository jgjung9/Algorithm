/**
 * https://www.acmicpc.net/problem/1358
 *
 * solution: 링크장 범위 안에 있는 플레이어를 카운트한다.
 */
#include <iostream>
#include <cmath>
using namespace std;

struct Player
{
    int x;
    int y;
};

int main()
{
    int w, h, x, y, p, ans = 0;
    Player player[50];
    cin >> w >> h >> x >> y >> p;
    int r = h / 2;
    for (int i = 0; i < p; i++)
    {
        cin >> player[i].x >> player[i].y;
        if (player[i].x < x)
        {
            if (pow(r, 2) >= (pow(x - player[i].x, 2) + pow(y + r - player[i].y, 2)))
                ans++;
        }
        else if (player[i].x > (x + w))
        {
            if (pow(r, 2) >= (pow(x + w - player[i].x, 2) + pow(y + r - player[i].y, 2)))
                ans++;
        }
        else
        {
            if (y <= player[i].y && y + h >= player[i].y)
                ans++;
        }
    }
    cout << ans;
    return 0;
}
