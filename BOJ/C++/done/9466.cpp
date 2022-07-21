/**
 * https://www.acmicpc.net/problem/9466
 *
 * solution: cycle 찾기
 */
#include <iostream>
#include <cstring>
#include <stack>
#include <map>
using namespace std;
int t, n, cnt;
int graph[100001];
bool visited[100001];
map<int, bool> cycle;
stack<int> s;

void DFS(int node)
{
    visited[node] = true;
    s.push(node);
    int nextNode = graph[node];
    auto it = cycle.find(nextNode);

    if (it != cycle.end())
    {
        while (!s.empty())
        {
            cycle.insert(make_pair(s.top(), false));
            s.pop();
        }
        return;
    }

    if (visited[nextNode])
    {
        cycle.insert(make_pair(nextNode, true));
        cnt++;
        while (s.top() != nextNode)
        {
            cycle.insert(make_pair(s.top(), true));
            cnt++;
            s.pop();
        }
        s.pop();
        while (!s.empty())
        {
            cycle.insert(make_pair(s.top(), false));
            s.pop();
        }
    }
    else
        DFS(nextNode);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> t;
    while (t--)
    {
        memset(visited, false, sizeof(visited));
        cycle.clear();
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> graph[i];
        cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
                DFS(i);
        }
        cout << n - cnt << '\n';
    }
    return 0;
}