/**
 * https://www.acmicpc.net/problem/1956
 *
 * solution: 플로이드 워셜
 * 각각 노드에서 모든 다른 노드까지의 최단거리를 구한후
 * 자기 자신까지 돌아오는 최단거리를 모두 비교하고
 * 최솟값을 출력한다.
 */
#include <iostream>
using namespace std;
const int INF = 1e9;
int v, e, from, to, dist, ans = INF;
int graph[401][401];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> v >> e;
    for (int i = 1; i <= v; i++)
        for (int j = 1; j <= v; j++)
            graph[i][j] = INF;

    for (int i = 0; i < e; i++)
    {
        cin >> from >> to >> dist;
        graph[from][to] = dist;
    }

    for (int k = 1; k <= v; k++)
    {
        for (int i = 1; i <= v; i++)
        {
            for (int j = 1; j <= v; j++)
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
        }
    }

    for (int i = 1; i <= v; i++)
    {
        if (graph[i][i])
            ans = min(ans, graph[i][i]);
    }

    if (ans == INF)
        cout << -1;
    else
        cout << ans;

    return 0;
}