/**
 * https://www.acmicpc.net/problem/1167
 *
 * solution: DFS를 한번 진행하여 시작점에서 가장 먼점을 구한다.
 * 가장 먼점을 기준으로 다시 DFS를 시작하여 그 점에서 가장 먼 경로를 구하면
 * 해당 경로가 가장 먼 경로가 된다.
 */
#include <iostream>
#include <vector>
using namespace std;

class Edge
{
public:
    Edge(int to, int cost)
    {
        this->to = to;
        this->cost = cost;
    }
    int to, cost;
};

int V, cost, from, to, start, maxDist = -1;
vector<Edge> tree[100001];
vector<int> dist(100001, -1);

void DFS(int node, int preDist)
{
    dist[node] = preDist;
    if (preDist > maxDist)
    {
        start = node;
        maxDist = preDist;
    }

    for (int i = 0; i < tree[node].size(); i++)
    {
        int nextNode = tree[node][i].to;
        if (dist[nextNode] != -1)
            continue;
        DFS(nextNode, preDist + tree[node][i].cost);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> V;
    for (int i = 0; i < V; i++)
    {
        cin >> from >> to;
        while (to != -1)
        {
            cin >> cost;
            tree[from].push_back(Edge(to, cost));
            cin >> to;
        }
    }
    DFS(1, 0);
    for (int i = 1; i <= V; i++)
        dist[i] = -1;
    maxDist = -1;
    DFS(start, 0);
    cout << maxDist;
    return 0;
}