/**
 * https://www.acmicpc.net/problem/1967
 *
 * solution: 트리의 지름을 구하는 대표적인 방법으로
 * 한 점에서 가장 먼점을 구하고 그 점을 시작점으로 하여 그 점에서
 * 가장 먼점으로 가는 경로가 지름이 된다.
 */
#include <iostream>
#include <vector>
using namespace std;

int n, from, to, cost, startPoint, maxDist;
vector<pair<int, int>> tree[10001];
bool visited[10001] = {false};

void DFS(int node, int dist)
{
    visited[node] = true;

    for (int i = 0; i < tree[node].size(); i++)
    {
        int nextNode = tree[node][i].first;
        int nextDist = dist + tree[node][i].second;
        if (visited[nextNode])
            continue;
        if (maxDist < nextDist)
        {
            maxDist = nextDist;
            startPoint = nextNode;
        }
        DFS(nextNode, nextDist);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> from >> to >> cost;
        tree[from].push_back(make_pair(to, cost));
        tree[to].push_back(make_pair(from, cost));
    }
    DFS(1, 0);

    maxDist = 0;
    for (int i = 1; i <= n; i++)
        visited[i] = false;

    DFS(startPoint, 0);
    cout << maxDist;
    return 0;
}