#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<int> visited(100001, 0);
vector<int> graph[100001];
int n, m, r, u, v, order = 1;

void BFS(int node)
{
    queue<int> q;
    visited[node] = order++;
    q.push(node);

    while (!q.empty())
    {
        node = q.front();
        q.pop();

        for (int i = 0; i < graph[node].size(); i++)
        {
            int nextNode = graph[node][i];
            if (visited[nextNode])
                continue;
            visited[nextNode] = order++;
            q.push(nextNode);
        }
    }
}

bool compare(int a, int b)
{
    return a > b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m >> r;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
        sort(graph[i].begin(), graph[i].end(), compare);

    BFS(r);

    for (int i = 1; i <= n; i++)
        cout << visited[i] << '\n';

    return 0;
}