#include <iostream>
#include <string>
using namespace std;

int n, normalCnt = 0, abnormalCnt = 0;
string s;
char graph[100][100];
bool visited[100][100] = {0};

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

void DFS(int x, int y, char color, bool normal)
{
    visited[x][y] = true;
    if (normal)
    {
        for (int dir = 0; dir < 4; dir++)
        {
            int nextX = x + dx[dir];
            int nextY = y + dy[dir];
            if (nextX < 0 || nextX >= n)
                continue;
            if (nextY < 0 || nextY >= n)
                continue;
            if (graph[nextX][nextY] != color)
                continue;
            if (visited[nextX][nextY])
                continue;
            DFS(nextX, nextY, color, normal);
        }
    }
    else
    {
        for (int dir = 0; dir < 4; dir++)
        {
            int nextX = x + dx[dir];
            int nextY = y + dy[dir];
            if (nextX < 0 || nextX >= n)
                continue;
            if (nextY < 0 || nextY >= n)
                continue;
            if (color == 'R' || color == 'G')
            {
                if (graph[nextX][nextY] == 'B')
                    continue;
            }
            else if (graph[nextX][nextY] != color)
                continue;
            if (visited[nextX][nextY])
                continue;
            DFS(nextX, nextY, color, normal);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < n; j++)
            graph[i][j] = s[j];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j])
            {
                DFS(i, j, graph[i][j], true);
                normalCnt++;
            }
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            visited[i][j] = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j])
            {
                DFS(i, j, graph[i][j], false);
                abnormalCnt++;
            }
        }
    }

    cout << normalCnt << ' ' << abnormalCnt;
    return 0;
}