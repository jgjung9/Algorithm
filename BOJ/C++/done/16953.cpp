#include <iostream>
#include <queue>
using namespace std;
using ll = long long;
const int MAX_SIZE = 1e9 + 1;
ll a, b;

void BFS(ll node)
{
    int cnt = 1;
    queue<pair<int, int>> q;
    q.push(make_pair(node, cnt));

    while (!q.empty())
    {
        node = q.front().first;
        cnt = q.front().second;
        q.pop();

        if (node == b)
        {
            cout << cnt;
            return;
        }

        for (int dir = 0; dir < 2; dir++)
        {
            ll nextNode = (dir == 0) ? node * 2 : node * 10 + 1;
            int nextCnt = cnt + 1;
            if (nextNode >= MAX_SIZE)
                continue;
            q.push(make_pair(nextNode, nextCnt));
        }
    }
    cout << -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> a >> b;
    BFS(a);
    return 0;
}