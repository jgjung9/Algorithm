/**
 * https://www.acmicpc.net/problem/24479
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> graph[100000];
vector<int> visited(100000, 0);
int cnt = 1;
void DFS(int vertex)
{
    if (visited[vertex])
        return;
    visited[vertex] = cnt;
    cnt++;
    for (int i = 0; i < graph[vertex].size(); i++)
        DFS(graph[vertex][i]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, r, u, v;
    cin >> n >> m >> r;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        graph[u - 1].push_back(v - 1);
        graph[v - 1].push_back(u - 1);
    }
    for (int i = 0; i < n; i++)
        sort(graph[i].begin(), graph[i].end());

    DFS(r - 1);
    for (int i = 0; i < n; i++)
        cout << visited[i] << '\n';
    return 0;
}