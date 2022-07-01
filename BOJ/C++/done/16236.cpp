/**
 * https://www.acmicpc.net/problem/16236
 *
 * solution: BFS를 이용한 최단거리 활용
 * 주어진 최단거리의 먹이가 여러개 일 경우 상단부터
 * 상단에서 거리가 동일한게 있을 경우 왼쪽부터 먹어야 하는 규칙으로 인해
 * 최단거리의 먹이들의 위치를 모두 기록하고 위치가 위 조건에 해당하는 것이
 * 맨 앞에 오도록 정렬하고 맨 앞에 있는 것을 방문한다.
 */
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;
int n, shark = 2, ans = 0;
int graph[20][20] = {0};
int visited[20][20] = {0};
vector<pair<int, int>> candidate;

bool compare(pair<int, int> a, pair<int, int> b)
{
    if (a.first > b.first)
        return false;
    else if (a.first == b.first && a.second > b.second)
        return false;
    else
        return true;
}

const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};
void BFS(int x, int y, int t)
{
    int cnt = 0, dist = 0;
    queue<tuple<int, int, int>> q;
    visited[x][y] = t;
    q.push(make_tuple(x, y, t));

    while (!q.empty())
    {
        tie(x, y, t) = q.front();
        q.pop();

        if (!candidate.empty() && t == dist)
        {
            sort(candidate.begin(), candidate.end(), compare);
            x = candidate[0].first, y = candidate[0].second;
            graph[x][y] = 0;
            cnt++;
            ans = t;
            if (cnt == shark)
            {
                shark++;
                cnt = 0;
            }
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    visited[i][j] = 0;
            q = queue<tuple<int, int, int>>();
            candidate.clear();
            visited[x][y] = t;
        }

        for (int dir = 0; dir < 4; dir++)
        {
            int nextX = x + dx[dir];
            int nextY = y + dy[dir];
            int nextT = t + 1;
            if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= n)
                continue;
            if (graph[nextX][nextY] > shark || visited[nextX][nextY])
                continue;

            if (graph[nextX][nextY] && graph[nextX][nextY] < shark)
            {
                dist = nextT;
                candidate.push_back(make_pair(nextX, nextY));
            }
            visited[nextX][nextY] = nextT;
            q.push(make_tuple(nextX, nextY, nextT));
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    int x, y;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
            if (graph[i][j] == 9)
            {
                x = i;
                y = j;
                graph[i][j] = 0;
            }
        }
    }
    BFS(x, y, 0);
    cout << ans;
    return 0;
}