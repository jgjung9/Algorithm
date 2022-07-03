/**
 * https://www.acmicpc.net/problem/2615
 *
 * solution: 단순 구현 / Brute Force
 */
#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
const int board_size = 19;
int board[board_size][board_size];
vector<pair<int, int>> black;
vector<pair<int, int>> white;

const int d[4][2] = {{-1, 0}, {0, -1}, {-1, -1}, {1, -1}};
const int dx[4] = {1, 0, 1, -1};
const int dy[4] = {0, 1, 1, 1};

bool check(int x, int y, int dir)
{
    int player = board[x][y];
    for (int i = 1; i <= 4; i++)
    {
        int nx = x + i * dx[dir];
        int ny = y + i * dy[dir];
        if (nx < 0 || ny < 0 || nx >= board_size || ny >= board_size)
            return false;
        if (board[nx][ny] != player)
            return false;
    }
    if (board[x + 5 * dx[dir]][y + 5 * dy[dir]] == player)
        return false;

    return true;
}

bool omok(int x, int y, int player)
{
    for (int i = 0; i < 4; i++)
    {
        int nx = x + d[i][0];
        int ny = y + d[i][1];
        if (nx < 0 || ny < 0 || nx >= board_size || ny >= board_size)
        {
            if (check(x, y, i))
                return true;
        }
        else if (board[nx][ny] != player)
        {
            if (check(x, y, i))
                return true;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    for (int i = 0; i < board_size; i++)
    {
        for (int j = 0; j < board_size; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 1)
                black.push_back(make_pair(i, j));
            else if (board[i][j] == 2)
                white.push_back(make_pair(i, j));
        }
    }

    for (int i = 0; i < black.size(); i++)
    {
        int x, y;
        tie(x, y) = black[i];
        if (omok(x, y, 1))
        {
            cout << 1 << '\n';
            cout << x + 1 << ' ' << y + 1;
            return 0;
        }
    }

    for (int i = 0; i < white.size(); i++)
    {
        int x, y;
        tie(x, y) = white[i];
        if (omok(x, y, 2))
        {
            cout << 2 << '\n';
            cout << x + 1 << ' ' << y + 1;
            return 0;
        }
    }

    cout << 0;
    return 0;
}