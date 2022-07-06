/**
 * https://www.acmicpc.net/problem/16929
 *
 * solution: DFS BFS 활용해 탐색을 진행한다
 * 직전에 방문한 노드를 방문할 순 없다. 만약
 * 이미 방문한 노드를 다시 방문하게 될 경우 싸이클이 존재하는 것으로 판단할 수 있다.
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int n, m;
bool cycle = false;
char graph[50][50];
bool visited[50][50] = { false };

const int dx[4] = { 0, 0, -1, 1 };
const int dy[4] = { -1, 1, 0, 0 };
void DFS(int x, int y, int px, int py) {
    char color = graph[x][y];
    if (visited[x][y]) 
    {
        cycle = true;
        return;
    }
    visited[x][y] = true;

    for (int dir = 0; dir < 4; dir++)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx == px && ny == py) 
            continue;
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) 
            continue;
        if (graph[nx][ny] != color) 
            continue;
        DFS(nx, ny, x, y);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m;
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < s.size(); j++)
            graph[i][j] = s[j];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j])
            {
                DFS(i, j, -1, -1);

                if (cycle)
                {
                    cout << "Yes";
                    return 0;
                }
            }
        }
    }

    cout << "No";
    return 0;
}