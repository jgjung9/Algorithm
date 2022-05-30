/**
 * https://www.acmicpc.net/problem/3085
 *
 * solution: brute force
 * 모든 사탕을 가능한 방식으로 옮겼을 때 최대 값을 매번 갱신해 준다.
 */
#include <iostream>
#include <algorithm>
using namespace std;

int maxCandy(int n, char board[][50])
{
    int maxCnt = 1;
    for (int i = 0; i < n; i++)
    {
        int rowCnt = 1;
        int colCnt = 1;
        for (int j = 1; j < n; j++)
        {
            if (board[i][j] == board[i][j - 1])
                rowCnt++;
            else
                rowCnt = 1;

            if (board[j][i] == board[j - 1][i])
                colCnt++;
            else
                colCnt = 1;
            maxCnt = max(maxCnt, max(colCnt, rowCnt));
        }
    }
    return maxCnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    char board[50][50];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];

    int answer = maxCandy(n, board);
    // left down right up
    int dy[4] = {0, 1, 0, -1};
    int dx[4] = {-1, 0, 1, 0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int dir = 0; dir < 4; dir++)
            {
                int nextY = i + dy[dir];
                int nextX = j + dx[dir];
                if (nextY < 0 || nextY >= n)
                    continue;
                if (nextX < 0 || nextX >= n)
                    continue;
                swap(board[i][j], board[nextY][nextX]);
                answer = max(answer, maxCandy(n, board));
                swap(board[i][j], board[nextY][nextX]);
            }
        }
    }

    cout << answer;
    return 0;
}