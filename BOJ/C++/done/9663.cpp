/**
 * https://www.acmicpc.net/problem/9663
 *
 * solution: n <= 15
 * 0, 0 부터 순서대로 놓을 수 있는 자리에 놓아본다
 * n 개를 놓을 때 까지 진행하고 놓을 수 없는 경우 뒤로 돌아온다.
 * 뒤로 돌아올 때마다 그때의 판 상황으로 맞춰준다.
 */
#include <iostream>
using namespace std;
int n, ans = 0;
int board[14][14] = {0};
int dx[4] = {-1, -1, 1, 1};
int dy[4] = {-1, 1, -1, 1};

bool check(int x, int y)
{

    for (int i = 0; i < n; i++)
    {
        if (board[x][i])
            return false;
    }

    for (int dir = 0; dir < 4; dir++)
    {
        int nextX = x;
        int nextY = y;
        while (true)
        {
            nextX += dx[dir];
            nextY += dy[dir];
            if (nextX < 0 || nextX >= n)
                break;
            if (nextY < 0 || nextY >= n)
                break;
            if (board[nextX][nextY])
                return false;
        }
    }
    return true;
}

void go(int n, int k)
{
    if (n == k)
    {
        ans++;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (!check(i, k))
            continue;
        board[i][k] = 1;
        go(n, k + 1);
        board[i][k] = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    go(n, 0);
    cout << ans;
    return 0;
}