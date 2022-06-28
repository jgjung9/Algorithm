/**
 * https://www.acmicpc.net/problem/13913
 *
 * solution: BFS를 통한 최단경로 탐색
 * BFS를 통해 현재 지점을 방문 하고 갈 수 지점을 계산 후
 * 해당 지점이 방문된 적이 없는 경우 방문을 진행한다.
 */
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
vector<int> parent(100001, -1);
stack<int> ans;
int n, k;
const int dx[3] = {2, -1, 1};

void path(int k)
{
    if (n == k)
    {
        ans.push(n);
        return;
    }

    ans.push(k);
    int p = parent[k];
    while (p != n)
    {
        ans.push(p);
        p = parent[p];
    }
    ans.push(n);
}

void BFS(int x)
{
    queue<int> q;
    parent[x] = x;
    q.push(x);

    while (!q.empty())
    {
        x = q.front();
        q.pop();
        for (int dir = 0; dir < 3; dir++)
        {
            int nextX = x;
            if (dir == 0)
                nextX *= dx[dir];
            else
                nextX += dx[dir];
            if (nextX < 0 || nextX > 100000)
                continue;
            if (parent[nextX] != -1)
                continue;
            parent[nextX] = x;
            q.push(nextX);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    BFS(n);
    path(k);

    cout << ans.size() - 1 << '\n';
    while (!ans.empty())
    {
        cout << ans.top() << ' ';
        ans.pop();
    }
    return 0;
}