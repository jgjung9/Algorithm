/**
 * https://www.acmicpc.net/problem/16928
 *
 * solution: BFS
 * 각 보드판에 자신의 넘버를 부여하고
 * 뱀과 사다리가 있는 판은 이동하는 판의 번호를 부여한후
 * BFS를 통해 방문을 진행하는데 뱀 또는 사다리를 만날 경우 해당 점 방문후
 * 곧바로 이동한 점까지 방문을 진행한다.
 */
#include <iostream>
#include <queue>
using namespace std;

int n, m, u, v;
int board[101];
int visited[101] = {0};
int d[6] = {1, 2, 3, 4, 5, 6};

void BFS(int node, int depth)
{
    queue<pair<int, int>> q;
    visited[node] = depth;
    q.push(make_pair(node, depth));

    while (!q.empty())
    {
        node = q.front().first, depth = q.front().second;
        q.pop();
        for (int dir = 0; dir < 6; dir++)
        {
            int nextNode = node + d[dir];
            int nextDepth = depth + 1;
            if (visited[nextNode])
                continue;

            if (board[nextNode] == nextNode)
            {
                visited[nextNode] = nextDepth;
                q.push(make_pair(nextNode, nextDepth));
            }
            else
            {
                visited[nextNode] = nextDepth;
                nextNode = board[nextNode];
                if (!visited[nextNode])
                {
                    visited[nextNode] = nextDepth;
                    q.push(make_pair(nextNode, nextDepth));
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i <= 100; i++)
        board[i] = i;

    for (int i = 0; i < n; i++)
    {
        cin >> u >> v;
        board[u] = v;
    }

    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        board[u] = v;
    }

    BFS(1, 1);
    cout << visited[100] - 1;
    return 0;
}