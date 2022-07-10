/**
 * https://www.acmicpc.net/problem/11404
 *
 * solution: Floyd-Warshall 알고리즘을 이용한
 * 모든 노드간의 최단거리 구하기
 */
#include <iostream>
using namespace std;
const int INF = 1e9;
int d[101][101] = {0};
int n, m, from, to, cost;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            d[i][j] = INF;

    for (int i = 0; i < m; i++)
    {
        cin >> from >> to >> cost;
        if (d[from][to] > cost)
            d[from][to] = cost;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == j)
                    continue;
                if (d[i][j] > d[i][k] + d[k][j])
                    d[i][j] = d[i][k] + d[k][j];
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (d[i][j] >= INF)
                cout << 0 << ' ';
            else
                cout << d[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}