/**
 * https://www.acmicpc.net/problem/14500
 *
 * solution: brute force
 * 첫번 째 점부터 순회하며 가능한 테트로미노를 넣고 얻어지는 값을 통해
 * 최댓값을 갱신한다.
 */
#include <iostream>
#include <cmath>
using namespace std;

// 0 : y 세로 , 1 : x 가로
int tetromino[19][3][2] = {
    {{0, 1}, {0, 2}, {0, 3}},
    {{1, 0}, {2, 0}, {3, 0}},
    {{1, 0}, {0, 1}, {1, 1}},
    {{1, 0}, {2, 0}, {2, 1}},
    {{1, 0}, {1, -1}, {1, -2}},
    {{0, 1}, {1, 1}, {2, 1}},
    {{1, 0}, {0, 1}, {0, 2}},
    {{1, 0}, {2, 0}, {2, -1}},
    {{0, 1}, {0, 2}, {1, 2}},
    {{0, 1}, {1, 0}, {2, 0}},
    {{1, 0}, {1, 1}, {1, 2}},
    {{1, 0}, {1, 1}, {2, 1}},
    {{1, 0}, {1, -1}, {2, -1}},
    {{0, 1}, {1, 0}, {1, -1}},
    {{0, 1}, {1, 1}, {1, 2}},
    {{0, 1}, {1, 1}, {0, 2}},
    {{1, 0}, {2, 0}, {1, 1}},
    {{1, -1}, {1, 0}, {1, 1}},
    {{1, 0}, {1, -1}, {2, 0}},
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int board[500][500] = {0};
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < 19; k++)
            {
                int sum = board[i][j];
                for (int dir = 0; dir < 3; dir++)
                {
                    int nextY = i + tetromino[k][dir][0];
                    int nextX = j + tetromino[k][dir][1];
                    if (nextY < 0 || nextY >= n)
                        break;
                    if (nextX < 0 || nextX >= m)
                        break;
                    sum += board[nextY][nextX];
                }
                answer = max(answer, sum);
            }
        }
    }
    cout << answer;
    return 0;
}