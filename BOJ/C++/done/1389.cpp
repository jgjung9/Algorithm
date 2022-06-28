/**
 * https://www.acmicpc.net/problem/1389
 *
 * solution: BFS이용한 모든 경로 탐색
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m, u, v, ans, minimum = 1e9, res = 0;
vector<int> visited(100, -1);
vector<int> graph[101];

void BFS(int node, int depth)
{
    queue<pair<int, int>> q;
    visited[node] = depth;
    q.push(make_pair(node, depth));

    while (!q.empty())
    {
        node = q.front().first, depth = q.front().second;
        q.pop();
        for (int i = 0; i < graph[node].size(); i++)
        {
            int nextNode = graph[node][i];
            int nextDep = depth + 1;
            if (visited[nextNode] != -1)
                continue;
            visited[nextNode] = nextDep;
            res += nextDep;
            q.push(make_pair(nextNode, nextDep));
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        BFS(i, 0);
        if (res < minimum)
        {
            ans = i;
            minimum = res;
        }
        res = 0;
        for (int j = 1; j <= n; j++)
            visited[j] = -1;
    }
    cout << ans;
    return 0;
}