/**
 * https://www.acmicpc.net/problem/13023
 *
 * solution: DFS의 아이디어를 이용해 접근
 * 0 -> 1 -> 2 -> 3 -> 4 탐색 즉 깊이가 4인것이 존재하면
 * 가능한 것으로 취급하고 종료
 * 0 - 3 이 연결되어 있어
 * 0 - 3 - 4 - 2 -1 순으로 탐색을 하게 될 경우 깊이는
 * 0   1   2   2  3 이므로 불가한 것으로 판단할 가능성 존재
 * 따라서 깊이 4까지 탐색을 하되 4보다 작은 깊이에서 뒤로 돌아갈 경우
 * 해당 노드를 방문하지 않은 것으로 처리할 필요가 있음
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