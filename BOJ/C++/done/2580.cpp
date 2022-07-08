/**
 * https://www.acmicpc.net/problem/2580
 *
 * solution: 스도쿠(sudoku)
 * 기본적인 백트래킹 문제로 스도쿠 규칙을 만족하도록 순서대로
 * 숫자를 넣어 진행하고 규칙을 만족하지 못하는 지점에 도달하면
 * 뒤로 돌아간다.
 */
#include <iostream>
#include <vector>
using namespace std;
int board[9][9];
bool done = false;
vector<pair<int, int>> blankPos;

bool checkRow(int row, int value)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == value)
            return false;
    }
    return true;
}

bool checkCol(int col, int value)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == value)
            return false;
    }
    return true;
}

bool checkRec(int x, int y, int value)
{
    for (int i = x; i < x + 3; i++)
    {
        for (int j = y; j < y + 3; j++)
        {
            if (board[i][j] == value)
                return false;
        }
    }
    return true;
}

void sudoku(int idx)
{
    if (idx == blankPos.size())
    {
        done = true;
        return;
    }

    int x = blankPos[idx].first;
    int y = blankPos[idx].second;
    for (int i = 1; i < 10; i++)
    {
        if (checkRow(x, i) && checkCol(y, i) && checkRec((x / 3) * 3, (y / 3) * 3, i))
        {
            board[x][y] = i;
            sudoku(idx + 1);
            if (done)
                return;
            board[x][y] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 0)
                blankPos.push_back(make_pair(i, j));
        }

    sudoku(0);
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            cout << board[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}