/**
 * https://www.acmicpc.net/problem/2668
 *
 * solution: DFS 싸이클 찾기
 * 1 -> 3 -> 1 , 5 -> 5
 * 즉 출발 점에서 시작점으로 돌아오는 결과를 찾는 것으로
 * 싸이클을 찾아야 하는 문제이다.
 */
#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
using namespace std;
int n, to, ans;
bool visited[101] = {false};
bool isCycle[101] = {false};
vector<int> graph[101];
stack<int> visitedNode;

void DFS(int node)
{
    visited[node] = true;
    visitedNode.push(node);
    int nextNode = graph[node][0];
    if (isCycle[nextNode])
        return;

    if (visited[nextNode])
    {
        isCycle[nextNode] = true;
        ans++;
        while (!visitedNode.empty() && visitedNode.top() != nextNode)
        {
            isCycle[visitedNode.top()] = true;
            ans++;
            visitedNode.pop();
        }
    }
    else
        DFS(nextNode);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> to;
        graph[i].push_back(to);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!isCycle[i])
        {
            memset(visited, false, sizeof(visited));
            DFS(i);
        }
    }
    cout << ans << '\n';
    for (int i = 1; i <= n; i++)
        if (isCycle[i])
            cout << i << '\n';
    return 0;
}