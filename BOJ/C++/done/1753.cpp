/**
 * https://www.acmicpc.net/problem/1753
 *
 * solution: Dijkstra 알고리즘
 * 모든 노드를 방문, 이미 방문한 노드라면 거리가 더 짧을 경우 다시 방문
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int v, e, start, from, to, cost;
vector<pair<int, int>> graph[20001];
vector<int> visited(20001, 2e9);

void Dijkstra(int node)
{
    priority_queue<pair<int, int>> pq;
    int dist = 0;
    visited[node] = dist;
    pq.push(make_pair(-dist, node));

    while (!pq.empty())
    {
        node = pq.top().second, dist = -pq.top().first;
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
    string ans = "";
    cin >> v >> e >> start;
    for (int i = 0; i < e; i++)
    {
        cin >> from >> to >> cost;
        graph[from].push_back(make_pair(to, cost));
    }

    Dijkstra(start);
    for (int i = 1; i <= v; i++)
    {
        if (visited[i] == 2e9)
            cout << "INF\n";
        else
            cout << visited[i] << '\n';
    }
    cout << ans;
    return 0;
}