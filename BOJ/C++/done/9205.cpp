/**
 * https://www.acmicpc.net/problem/9205
 *
 * solution: BFS
 * 목적지를 편의점과 페스티벌로 설정하고
 * 목적지까지가 거리가 1000 이하일 경우 갈 수 있는 것이고
 * 이상일 경우 갈 수 없다.
 * 목적지를 방문하면 방문했음을 체크하고 재방문하지 않도록 한다.
 * 최종적으로 BFS를 통한 방문이 완료되고
 * 페티스벌에 방문한적이 있는 확인한후 없을 경우 sad
 * 있을 경우 happy를 출력한다.
 */
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
int t, n;
vector<pair<int, int>> destiantion;
vector<bool> visited;

void BFS(int x, int y)
{
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));

    while (!q.empty())
    {
        tie(x, y) = q.front();
        q.pop();

        for (int i = 0; i < destiantion.size(); i++)
        {
            int nx, ny;
            tie(nx, ny) = destiantion[i];
            if (visited[i])
                continue;
            if (abs(nx - x) + abs(ny - y) > 1000)
                continue;
            visited[i] = true;
            q.push(make_pair(nx, ny));
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
        cin >> n;
        pair<int, int> start;
        int x, y;
        cin >> x >> y;
        start = make_pair(x, y);
        for (int i = 0; i <= n; i++)
        {
            cin >> x >> y;
            destiantion.push_back(make_pair(x, y));
            visited.push_back(false);
        }
        BFS(start.first, start.second);
        if (visited[visited.size() - 1])
            cout << "happy\n";
        else
            cout << "sad\n";

        destiantion.clear();
        visited.clear();
    }
    return 0;
}