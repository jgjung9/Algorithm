/**
 * https://www.acmicpc.net/problem/11403
 *
 * solution: DFS를 활용한 해결
 */
#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[100];
bool visited[100] = {false};
bool path[100][100] = {false};

void DFS(int node)
{
    for (int i = 0; i < graph[node].size(); i++)
    {
        int nextNode = graph[node][i];
        if (visited[nextNode])
            continue;
        visited[nextNode] = true;
        DFS(nextNode);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, v;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v;
            if (v)
                graph[i].push_back(j);
        }
    }

    for (int i = 0; i < n; i++)
    {
        DFS(i);
        for (int j = 0; j < n; j++)
        {
            if (visited[j])
            {
                path[i][j] = 1;
                visited[j] = false;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << path[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}