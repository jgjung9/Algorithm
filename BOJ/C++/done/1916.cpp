/**
 * https://www.acmicpc.net/problem/1916
 *
 * solution: Dijkstra 알고리즘
 * 이미 방문 한 점이라도 거리가 더 가까울 경우 다 방문
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m, from, to, cost;
vector<pair<int, int>> graph[1001];
vector<int> visited(1001, -1);

void BFS(int node)
{
    queue<pair<int, int>> q;
    int dist = 0;
    visited[node] = dist;
    q.push(make_pair(node, dist));

    while (!q.empty())
    {
        node = q.front().first, dist = q.front().second;
        q.pop();
        if (visited[node] < dist)
            continue;
        for (int i = 0; i < graph[node].size(); i++)
        {
            int nextNode = graph[node][i].first;
            int nextDist = dist + graph[node][i].second;
            if (visited[nextNode] == -1 || visited[nextNode] > nextDist)
            {
                visited[nextNode] = nextDist;
                q.push(make_pair(nextNode, nextDist));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> from >> to >> cost;
        graph[from].push_back(make_pair(to, cost));
    }
    int start, target;
    cin >> start >> target;
    BFS(start);
    cout << visited[target];
    return 0;
}