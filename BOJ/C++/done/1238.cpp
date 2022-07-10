/**
 * https://www.acmicpc.net/problem/1238
 *
 * solution: Dijkstra 를 이용한 최단거리 구하기
 */
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n, m, x, from, to, cost;
vector<pair<int, int>> graph[1001];
vector<int> visited(1001, 2e9);
vector<int> ans(1001, 0);

void Dijkstra(int node)
{
    for (int i = 1; i <= n; i++)
        visited[i] = 2e9;

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
    cin >> n >> m >> x;
    for (int i = 0; i < m; i++)
    {
        cin >> from >> to >> cost;
        graph[from].push_back(make_pair(to, cost));
    }
    Dijkstra(x);
    for (int i = 1; i <= n; i++)
        ans[i] = visited[i];

    for (int i = 1; i <= n; i++)
    {
        if (i == x)
            continue;

        Dijkstra(i);
        ans[i] += visited[x];
    }

    int maxDist = 0;
    for (int i = 1; i <= n; i++)
        maxDist = max(maxDist, ans[i]);
    cout << maxDist;

    return 0;
}