/**
 * https://www.acmicpc.net/problem/13549
 *
 * solution: BFS를 통한 최단경로 구하기
 * 현재 지점에서 갈수 있는 지점을 구하고
 * 방문하지 않는 경우에는 그냥 방문을 진행하고
 * 방문을 기존에 한 경우에는 현재의 비용이 더 적은 상태라면
 * 방문을 진행
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, k;
vector<int> visited(100001, -1);
const int dx[3] = {2, -1, 1};
void BFS(int x, int time)
{
    queue<pair<int, int>> q;
    visited[x] = time;
    q.push(make_pair(x, time));

    while (!q.empty())
    {
        x = q.front().first, time = q.front().second;
        q.pop();
        for (int dir = 0; dir < 3; dir++)
        {
            int nextX = x;
            int nextTime = time;
            if (dir == 0)
                nextX *= dx[dir];
            else
            {
                nextX += dx[dir];
                nextTime += 1;
            }
            if (nextX < 0 || nextX > 100000)
                continue;
            if (visited[nextX] == -1)
            {
                visited[nextX] = nextTime;
                q.push(make_pair(nextX, nextTime));
            }
            else if (visited[nextX] > nextTime)
            {
                visited[nextX] = nextTime;
                q.push(make_pair(nextX, nextTime));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    BFS(n, 0);
    cout << visited[k];
    return 0;
}