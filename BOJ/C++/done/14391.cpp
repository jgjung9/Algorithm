/**
 * https://www.acmicpc.net/problem/14391
 *
 * solution: brute force
 * 1 x 1 각각의 칸을 가로 세로를 결정한다.
 * 결정된 보드를 규칙에 따라 합을 구한다.
 * 보드는 N X M 칸을 가지고 있으므로
 * 모든 칸을 가로와 세로를 결정하는 경우의 수는 O(2^NM)이다.
 * 또한 결정된 이후 보드를 순회하면서 결과값을 계산하는 것은 O(NM)이다.
 * 따라서 결정방식(부르트 포스/백트래킹)의 시간 복잡도는 O(NM*2^NM)
 * N, M <= 4이므로 최대  2^20 -> 약 10^6 충분히 사용가능한 방법이다.
 */
#include <iostream>
#include <string>
using namespace std;
int n, m, ans = 0;
int board[4][4];
int color[4][4]; // 1 : 가로 2 : 세로

int calculateBoard()
{
    bool visited[4][4] = {false};
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j])
                continue;
            int sum = board[i][j];
            visited[i][j] = true;
            if (color[i][j] == 1)
            {
                int next = j + 1;
                while (color[i][next] == color[i][j])
                {
                    if (next == m)
                        break;
                    sum = sum * 10 + board[i][next];
                    visited[i][next] = true;
                    next++;
                }
            }
            else
            {
                int next = i + 1;
                while (color[next][j] == color[i][j])
                {
                    if (next == n)
                        break;
                    sum = sum * 10 + board[next][j];
                    visited[next][j] = true;
                    next++;
                }
            }
            res += sum;
        }
    }
    return res;
}

void divideBoard(int idx)
{
    if (idx == n * m)
    {
        ans = max(ans, calculateBoard());
        return;
    }

    int x = idx / m;
    int y = idx % m;
    color[x][y] = 1;
    divideBoard(idx + 1);
    color[x][y] = 2;
    divideBoard(idx + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m;
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < m; j++)
            board[i][j] = s[j] - '0';
    }

    divideBoard(0);
    cout << ans;
    return 0;
}