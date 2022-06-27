/**
 * https://www.acmicpc.net/problem/10971
 *
 * solution: 외판원 순회2
 * 모든 경로를 순회하는 브루트 포스를 이용해 해결한다.
 */
#include <iostream>
using namespace std;
int n, start = 0, ans = 1e9;
int w[10][10];
int visited[10] = {0};

void travel(int n, int k, int now)
{
    if (n == k + 1)
    {
        if (w[now][0] == 0)
            return;

        int sum = w[now][0];
        for (int i = 0; i < n; i++)
            sum += visited[i];
        if (sum < ans)
            ans = sum;
        return;
    }

    for (int i = 1; i < n; i++)
    {
        if (visited[i])
            continue;
        if (w[now][i] == 0)
            continue;
        visited[i] = w[now][i];
        travel(n, k + 1, i);
        visited[i] = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> w[i][j];

    travel(n, 0, 0);
    cout << ans;
    return 0;
}