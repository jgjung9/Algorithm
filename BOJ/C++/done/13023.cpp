/**
 * https://www.acmicpc.net/problem/13023
 *
 * solution:
 */
#include <iostream>
#include <vector>
using namespace std;
int n, m;
bool isPossible = false;
vector<int> graph[2000];
vector<bool> visited(2000, false);

void DFS(int node, int dep)
{
    if (dep == 4)
    {
        isPossible = true;
        return;
    }

    visited[node] = true;
    for (int i = 0; i < graph[node].size(); i++)
    {
        if (visited[graph[node][i]])
            continue;
        DFS(graph[node][i], dep + 1);
        if (isPossible)
            return;
    }
    visited[node] = false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    int v, u;
    for (int i = 0; i < m; i++)
    {
        cin >> v >> u;
        graph[v].push_back(u);
        graph[u].push_back(v);
    }

    for (int i = 0; i < n; i++)
    {
        DFS(i, 0);
    }
    if (isPossible)
        cout << 1;
    else
        cout << 0;

    return 0;
}