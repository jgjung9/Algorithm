/**
 * https://www.acmicpc.net/problem/1780
 *
 * solution: 시작 좌표와 크기를 기준으로 분할 정복
 */
#include <iostream>
using namespace std;
int n, minusCnt = 0, plusCnt = 0, zeroCnt = 0;
int board[2187][2187];

bool check(int startX, int startY, int n)
{
    int value = board[startX][startY];
    for (int i = startX; i < startX + n; i++)
    {
        for (int j = startY; j < startY + n; j++)
        {
            if (value != board[i][j])
                return false;
        }
    }

    if (value == 0)
        zeroCnt++;
    else if (value == -1)
        minusCnt++;
    else
        plusCnt++;

    return true;
}

void divide(int startX, int startY, int n)
{
    if (check(startX, startY, n))
        return;

    int q = n / 3;
    divide(startX, startY, q);
    divide(startX, startY + q, q);
    divide(startX, startY + 2 * q, q);

    divide(startX + q, startY, q);
    divide(startX + q, startY + q, q);
    divide(startX + q, startY + 2 * q, q);

    divide(startX + 2 * q, startY, q);
    divide(startX + 2 * q, startY + q, q);
    divide(startX + 2 * q, startY + 2 * q, q);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];

    divide(0, 0, n);
    cout << minusCnt << '\n';
    cout << zeroCnt << '\n';
    cout << plusCnt;
    return 0;
}