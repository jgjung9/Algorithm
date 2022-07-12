#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int f, s, g, u, d, ans = 0;
vector<int> visited(1e6 + 1, 1e9);
int dir[2];

void BFS(int floor)
{
    queue<pair<int, int>> q;
    int dep = 0;
    visited[floor] = dep;
    q.push(make_pair(floor, dep));

    while (!q.empty())
    {
        floor = q.front().first, dep = q.front().second;
        q.pop();

        for (int i = 0; i < 2; i++)
        {
            int nextFloor = floor + dir[i];
            int nextDep = dep + 1;
            if (nextFloor <= 0 || nextFloor > f)
                continue;
            if (visited[nextFloor] <= nextDep)
                continue;
            visited[nextFloor] = nextDep;
            q.push(make_pair(nextFloor, nextDep));
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> f >> s >> g >> u >> d;
    dir[0] = u, dir[1] = -d;
    BFS(s);

    if (visited[g] == 1e9)
        cout << "use the stairs";
    else
        cout << visited[g];

    return 0;
}