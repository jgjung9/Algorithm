#include <iostream>
#include <string>
using namespace std;
string board;

bool Acheck(int idx)
{
    return board[idx] == 'X' && board[idx + 1] == 'X' && board[idx + 2] == 'X' && board[idx + 3] == 'X';
}

bool Bcheck(int idx)
{
    return board[idx] == 'X' && board[idx + 1] == 'X';
}

bool solve(int idx, int size)
{
    if (idx == size)
        return true;

    if (board[idx] == '.')
    {
        if (solve(idx + 1, size))
            return true;
    }
    else
    {
        if (Acheck(idx))
        {
            board[idx] = board[idx + 1] = board[idx + 2] = board[idx + 3] = 'A';
            if (solve(idx + 4, size))
                return true;
            board[idx] = board[idx + 1] = board[idx + 2] = board[idx + 3] = 'X';
        }
        if (Bcheck(idx))
        {
            board[idx] = board[idx + 1] = 'B';
            if (solve(idx + 2, size))
                return true;
            board[idx] = board[idx + 1] = 'X';
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> board;

    if (solve(0, board.size()))
        cout << board;
    else
        cout << -1;
    return 0;
}