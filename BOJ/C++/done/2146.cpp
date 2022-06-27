/**
 * https://www.acmicpc.net/problem/2146
 *
 * solution: BFS 모든 노드를 탐색한다.
 * 노드를 탐색할때마다 1번과 2번 번호를 붙인다.
 * 부모 노드가 1일 경우 2, 2일 경우 1로 번호를 매긴다.
 * 이미 번호가 매겨진 경우 탐색하지 번호를 갱신하지 않는다.
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int K, V, E, u, v;
vector<int> graph[20001];
vector<int> visited(20001, 0);

bool BFS(int node, int n)
{
    queue<pair<int, int>> q;
    visited[node] = n;
    q.push(make_pair(node, n));
    while (!q.empty())
    {
        node = q.front().first;
        n = q.front().second;
        q.pop();
        for (int i = 0; i < graph[node].size(); i++)
        {
            int next = graph[node][i];
            if (!visited[next])
            {
                visited[next] = 3 - n;
                q.push(make_pair(next, 3 - n));
            }
            else if (visited[next] == visited[node])
                return false;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> K;
    while (K--)
    {
        cin >> V >> E;
        for (int i = 0; i < E; i++)
        {
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        bool check = true;
        for (int i = 1; i <= V; i++)
        {
            if (!visited[i] && !BFS(i, 1))
            {
                check = false;
                break;
            }
        }

        if (check)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';

        for (int i = 1; i <= V; i++)
        {
            graph[i].clear();
            visited[i] = 0;
        }
    }
    return 0;
}