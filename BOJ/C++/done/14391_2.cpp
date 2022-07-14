/**
 * https://www.acmicpc.net/problem/14391
 *
 * solution: 비트마스크를 이용한 풀이
 */
#include <iostream>
#include <string>
using namespace std;
int n, m, ans = 0;
int paper[4][4];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++)
            paper[i][j] = str[j] - '0';
    }

    for (int k = 0; k < (1 << (n * m)); k++)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            int cur = 0;
            for (int j = 0; j < m; j++)
            {
                if (k & (1 << (i * m + j)))
                {
                    sum += cur;
                    cur = 0;
                }
                else
                    cur = cur * 10 + paper[i][j];
            }
            sum += cur;
        }

        for (int j = 0; j < m; j++)
        {
            int cur = 0;
            for (int i = 0; i < n; i++)
            {
                if (k & (1 << (i * m + j)))
                    cur = cur * 10 + paper[i][j];
                else
                {
                    sum += cur;
                    cur = 0;
                }
            }
            sum += cur;
        }
        ans = max(ans, sum);
    }
    cout << ans;
    return 0;
}