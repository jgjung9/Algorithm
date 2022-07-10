/**
 * https://www.acmicpc.net/problem/1504
 *
 * solution: Dijkstra 알고리즘을 이용한 최단경로 문제
 * 정점 v1 v2를 무조건 지나면서 1에서 출발하여 N에 도달해야함
 * 1 -> v1 -> v2 -> N
 * 1 -> v2 -> v1 -> N   두가지 경로가 존재
 * v1, v2 에 대해 다익스트라 알고리즘을 각각 실행하여
 * v1 에서 v2까지 의 최단거리와 v1 -> 1  v1 -> N
 * v2 -> 1  v2 -> N 사이의 최단거리를 각각 구해 위
 * 두 경로중 더 짧은 경로를 선택한다.
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, e, from, to, cost, v1, v2;
long long ans, candidate, candidate2;
vector<pair<int, int>> graph[801];
vector<int> visited(801, 1e9);

void Dijkstra(int node)
{
    for (int i = 1; i <= n; i++)
        visited[i] = 1e9;

    priority_queue<pair<int, int>> pq;
    int dist = 0;
    visited[node] = dist;
    pq.push(make_pair(-dist, node));

    while (!pq.empty())
    {
        dist = -pq.top().first, node = pq.top().second;
        pq.pop();

        if (visited[node] < dist)
            continue;

        for (int i = 0; i < graph[node].size(); i++)
        {
            int nextNode = graph[node][i].first;
            int nextDist = dist + graph[node][i].second;
            if (visited[nextNode] <= nextDist)
                continue;
            visited[nextNode] = nextDist;
            pq.push(make_pair(-nextDist, nextNode));
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        cin >> from >> to >> cost;
        graph[from].push_back(make_pair(to, cost));
        graph[to].push_back(make_pair(from, cost));
    }
    cin >> v1 >> v2;

    ans = candidate = candidate2 = 0;
    Dijkstra(v1);
    candidate += visited[1] + visited[v2];
    candidate2 += visited[n] + visited[v2];
    Dijkstra(v2);
    candidate += visited[n];
    candidate2 += visited[1];

    ans = min(candidate, candidate2);
    if (ans >= 1e9)
        cout << -1;
    else
        cout << ans;
    return 0;
}