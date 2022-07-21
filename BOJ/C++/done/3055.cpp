/**
 * https://www.acmicpc.net/problem/3055
 *
 * solution: BFS
 * 이동하는 정점이 벽과 물이 아닐 경우 이동한다
 * 이동한 자리가 물로 바뀌는 경우는 제외해준다.
 * 시간이 지나면 물이 늘어나도록 만들어 준다.
 * 목표 하는 지점에 도착할 경우 해당하는 시간을 출력하고
 * BFS가 끝날 때까지 도착하지 못하면 "KAKTUS"를 출력한다.
 */
#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;
int r, c;
pair<int, int> start;
pair<int, int> dest;
vector<pair<int, int>> water;
char board[50][50];
int visited[50][50];
bool dep[1000];
const int dx[4] = {0, -1, 0, 1};
const int dy[4] = {-1, 0, 1, 0};

void makeWater()
{
    vector<pair<int, int>> newWater;

    for (int i = 0; i < water.size(); i++)
    {
        int x, y;
        x = water[i].first, y = water[i].second;
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= r || ny < 0 || ny >= c)
                continue;
            if (board[nx][ny] == 'X' || board[nx][ny] == 'D' || board[nx][ny] == '*')
                continue;
            board[nx][ny] = '*';
            newWater.push_back(make_pair(nx, ny));
        }
    }
    water = newWater;
}

void BFS(int x, int y)
{
    int dist = 1;
    queue<pair<int, int>> q;
    visited[x][y] = dist;
    q.push(make_pair(x, y));
    dep[dist] = true;

    while (!q.empty())
    {
        x = q.front().first, y = q.front().second;
        dist = visited[x][y];
        q.pop();

        if (x == dest.first && y == dest.second)
        {
            cout << dist - 1;
            return;
        }

        if (!dep[dist])
        {
            dep[dist] = true;
            makeWater();
        }

        if (board[x][y] == '*')
            continue;

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= r || ny < 0 || ny >= c)
                continue;
            if (board[nx][ny] == '*' || board[nx][ny] == 'X' || visited[nx][ny])
                continue;
            visited[nx][ny] = dist + 1;
            q.push(make_pair(nx, ny));
        }
    }
    cout << "KAKTUS";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < c; j++)
        {
            board[i][j] = str[j];
            if (board[i][j] == 'S')
                start = make_pair(i, j);
            else if (board[i][j] == 'D')
                dest = make_pair(i, j);
            else if (board[i][j] == '*')
                water.push_back(make_pair(i, j));
        }
    }
    BFS(start.first, start.second);
    return 0;
}