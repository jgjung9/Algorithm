/**
 * https://www.acmicpc.net/problem/1080
 *
 * solution: greedy
 */
#include <iostream>
#include <string>
using namespace std;
int n, m, ans = 0;
int matA[50][50], matB[50][50];

void convert(int x, int y)
{
    for (int i = x; i < x + 3; i++)
        for (int j = y; j < y + 3; j++)
            matA[i][j] = (matA[i][j] + 1) % 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m;
    string str;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        for (int j = 0; j < m; j++)
            matA[i][j] = str[j] - '0';
    }
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        for (int j = 0; j < m; j++)
            matB[i][j] = str[j] - '0';
    }

    for (int i = 0; i < n - 2; i++)
    {
        for (int j = 0; j < m - 2; j++)
        {
            if (matA[i][j] != matB[i][j])
            {
                convert(i, j);
                ans++;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matA[i][j] != matB[i][j])
            {
                cout << -1;
                return 0;
            }
        }
    }
    cout << ans;
    return 0;
}