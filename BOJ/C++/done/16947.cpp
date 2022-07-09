/**
 * https://www.acmicpc.net/problem/16947
 *
 * solution: DFS를 활용해 싸이클을 찾는다
 * 싸이클은 찾으면 DFS를 종료한다
 * 각각의 정점이 싸이클일 경우 0을 출력하고
 * 싸이클이 아닐경우 BFS를 진행해 싸이클까지의 거리를 찾고
 * 해당 거리를 출력한다.
 */
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
int n;
bool foundCycle = false;
vector<int> visited(3001, 0);
vector<bool> isCycle(3001, false);
vector<int> graph[3001];
stack<int> s;

void DFS(int node, int prevNode)
{
    if (visited[node])
    {
        isCycle[node] = true;
        while (s.top() != node)
        {
            int cycle = s.top();
            s.pop();
            isCycle[cycle] = true;
        }
        foundCycle = true;
        return;
    }

    visited[node] = true;
    s.push(node);

    for (int i = 0; i < graph[node].size(); i++)
    {
        int nextNode = graph[node][i];
        if (nextNode == prevNode)
            continue;
        DFS(nextNode, node);
        if (foundCycle)
            return;
    }
    s.pop();
}

void BFS(int node, int dist)
{
    for (int i = 1; i <= n; i++)
        visited[i] = 0;

    queue<pair<int, int>> q;
    visited[node] = dist;
    q.push(make_pair(node, dist));

    while (!q.empty())
    {
        node = q.front().first, dist = q.front().second;
        q.pop();

        for (int i = 0; i < graph[node].size(); i++)
        {
            int nextNode = graph[node][i];
            int nextDist = dist + 1;
            if (visited[nextNode])
                continue;
            visited[nextNode] = nextDist;
            q.push(make_pair(nextNode, nextDist));
            if (isCycle[nextNode])
            {
                cout << dist << ' ';
                return;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n;
    int u, v;
    for (int i = 0; i < n; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    DFS(1, 1);

    for (int i = 1; i <= n; i++)
    {
        if (isCycle[i])
            cout << 0 << ' ';
        else
            BFS(i, 1);
    }
    return 0;
}