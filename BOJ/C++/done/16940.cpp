/**
 * https://www.acmicpc.net/problem/16940
 *
 * solution: BFS
 * 그래프를 인접리스트 방식으로 만들고
 * 인접리스트의 순서를 주어진 방문순서대로 정렬한후
 * BFS의 방문을 진행한다. 방문순서가 주어진 순서와 같을경우 1 아닐경우 0을 출력
 */
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX_SIZE = 100001;
int n, u, v, order;
vector<int> graph[MAX_SIZE];
bool visited[MAX_SIZE] = {false};
int orderList[MAX_SIZE];

void BFS(int node)
{
    queue<int> q;
    order = 0;
    visited[node] = true;
    q.push(node);
    if (orderList[node] != order++)
    {
        cout << 0;
        return;
    }

    while (!q.empty())
    {
        node = q.front();
        q.pop();

        for (int i = 0; i < graph[node].size(); i++)
        {
            int nextNode = graph[node][i];
            if (visited[nextNode])
                continue;
            visited[nextNode] = true;
            q.push(nextNode);
            if (orderList[nextNode] != order++)
            {
                cout << 0;
                return;
            }
        }
    }
    cout << 1;
}

bool compare(int a, int b)
{
    return orderList[a] < orderList[b];
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

    for (int i = 0; i < n; i++)
    {
        cin >> order;
        orderList[order] = i;
    }

    for (int i = 1; i <= n; i++)
        sort(graph[i].begin(), graph[i].end(), compare);

    BFS(1);
    return 0;
}