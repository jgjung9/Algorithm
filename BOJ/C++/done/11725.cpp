/**
 * https://www.acmicpc.net/problem/11725
 *
 * solution: DFS BFS를 통해 트리를 탐색하고
 * 방문할때 마다 부모를 기록한다.
 */
#include <iostream>
#include <vector>
using namespace std;
int n, u, v;
vector<int> tree[100001];
vector<int> parent(100001, 0);

void DFS(int node, int pre)
{
    parent[node] = pre;
    for (int i = 0; i < tree[node].size(); i++)
    {
        int nextNode = tree[node][i];
        if (parent[nextNode])
            continue;
        DFS(nextNode, node);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    DFS(1, 1);
    for (int i = 2; i <= n; i++)
        cout << parent[i] << '\n';

    return 0;
}
