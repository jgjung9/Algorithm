/**
 * https://www.acmicpc.net/problem/2667
 *
 * solution: DFS를 활용해 연결요소를 개수를 구하고
 * 한번의 DFS가 진행될 때 탐색한 노드의 개수를 오름차순으로 출력
 */
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool visited[25][25] = {false};
int graph[25][25] = {0};
int dy[4] = {0, 1, 0, -1};
int dx[4] = {-1, 0, 1, 0};
int DFS(int y, int x, int n)
{
    int cnt = 0;
    if (visited[y][x])
        return cnt;
    visited[y][x] = true;
    cnt++;
    for (int dir = 0; dir < 4; dir++)
    {
        int nextY = y + dy[dir];
        int nextX = x + dx[dir];
        if (nextY < 0 || nextY >= n)
            continue;
        if (nextX < 0 || nextX >= n)
            continue;
        if (graph[nextY][nextX] == 0)
            continue;
        cnt += DFS(nextY, nextX, n);
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int component = 0;
    vector<int> answer;
    for (int i = 0; i < n; i++)
    {
        string row;
        cin >> row;
        for (int j = 0; j < row.size(); j++)
            graph[i][j] = row[j] - '0';
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] == 1 && !visited[i][j])
            {
                answer.push_back(DFS(i, j, n));
                component++;
            }
        }
    }
    sort(answer.begin(), answer.end());
    cout << component << '\n';
    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << '\n';

    return 0;
}