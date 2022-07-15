#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
int t, a, b;
vector<int> visited(10000, -1);
vector<pair<int, char>> parent(10000);

int calculate(int n, int command)
{
    if (command == 0)
    {
        return 2 * n % 10000;
    }
    else if (command == 1)
    {
        if (n == 0)
            return 9999;
        else
            return n - 1;
    }
    else if (command == 2)
    {
        int d1 = n / 1000;
        n = n % 1000;
        return n * 10 + d1;
    }
    else
    {
        int d4 = n % 10;
        n = n / 10;
        return d4 * 1000 + n;
    }
}

void BFS(int node)
{
    queue<pair<int, int>> q;
    int dist = 0;
    visited[node] = 0;
    parent[node] = make_pair(node, -1);
    q.push(make_pair(node, dist));

    while (!q.empty())
    {
        node = q.front().first, dist = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int next = calculate(node, i);
            if (visited[next] > -1 && visited[next] <= dist + 1)
                continue;
            visited[next] = dist + 1;
            if (i == 0)
                parent[next] = make_pair(node, 'D');
            else if (i == 1)
                parent[next] = make_pair(node, 'S');
            else if (i == 2)
                parent[next] = make_pair(node, 'L');
            else
                parent[next] = make_pair(node, 'R');
            q.push(make_pair(next, dist + 1));
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        for (int i = 0; i < 10000; i++)
            visited[i] = -1;

        BFS(a);

        string ans = "";
        while (true)
        {
            if (b == parent[b].first)
                break;
            ans = parent[b].second + ans;
            b = parent[b].first;
        }

        cout << ans << '\n';
    }

    return 0;
}