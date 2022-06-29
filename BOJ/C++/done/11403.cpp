/**
 * https://www.acmicpc.net/problem/11403
 *
 * solution: 플로이드 워셜 알고리즘을 활용한 해결
 */
#include <iostream>
#include <vector>
using namespace std;
int n, v;
int graph[100][100];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (graph[i][k] && graph[k][j])
                    graph[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << graph[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}