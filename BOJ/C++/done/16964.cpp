/**
 * https://www.acmicpc.net/problem/16964
 *
 * solution: DFS를 진행한다
 * 그래프를 인접리스트 형식으로 구현하고
 * 주어진 순서대로 노드들의 순서를 정렬한다
 * DFS(1)을 진행하는데
 * 방문 순서가 주어진 순서와 다르다면 옳바른 순서가 아니다.
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_SIZE = 1e5 + 1;
int n, u, v, order;
bool isRight = true;
vector<int> graph[MAX_SIZE];
vector<int> orderList(MAX_SIZE, 0);
bool visited[MAX_SIZE] = {false};

void DFS(int node)
{
    visited[node] = true;
    order++;
    if (orderList[node] != order)
    {
        isRight = false;
        return;
    }

    for (int i = 0; i < graph[node].size(); i++)
    {
        int nextNode = graph[node][i];
        if (visited[nextNode])
            continue;
        DFS(nextNode);
    }
}

bool compare(int u, int v)
{
    return orderList[u] < orderList[v];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> order;
        orderList[order] = i;
    }

    for (int i = 1; i <= n; i++)
        sort(graph[i].begin(), graph[i].end(), compare);

    order = 0;
    DFS(1);

    if (isRight)
        cout << 1;
    else
        cout << 0;

    return 0;
}