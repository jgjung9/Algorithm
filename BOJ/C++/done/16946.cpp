/**
 * https://www.acmicpc.net/problem/16946
 *
 * solution: 벽이 아닌 공간을 그룹으로 나누고 그 크기를 구한다.
 * 벽을 돌며 인접 빈공간의 그룹번호를 체크하고 해당 공간을 크기를
 * 모두 더하고 1을 추가로 더해준다.
 * 해당 값을 % 10 하여 출력한다.
 */
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <set>
using namespace std;
int n, m;
bool visited[1000][1000];
int board[1000][1000];
int result[1000][1000];
int group[1000][1000];
vector<int> groupSize;

const int dx[4] = {0, -1, 0, 1};
const int dy[4] = {-1, 0, 1, 0};
void BFS(int x, int y)
{
    int cnt = 1;
    int groupNumber = groupSize.size();
    queue<pair<int, int>> q;
    visited[x][y] = true;
    group[x][y] = groupNumber;
    q.push(make_pair(x, y));

    while (!q.empty())
    {
        x = q.front().first, y = q.front().second;
        q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (board[nx][ny] || visited[nx][ny])
                continue;
            visited[nx][ny] = true;
            group[nx][ny] = groupNumber;
            q.push(make_pair(nx, ny));
            cnt++;
        }
    }
    groupSize.push_back(cnt);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++)
            board[i][j] = str[j] - '0';
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!board[i][j] && !visited[i][j])
                BFS(i, j);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 0)
                cout << 0;
            else
            {
                int res = 1;
                set<int> near;
                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                        continue;
                    if (visited[nx][ny])
                        near.insert(group[nx][ny]);
                }
                for (auto it = near.begin(); it != near.end(); it++)
                    res += groupSize[*it];
                cout << res % 10;
            }
        }
        cout << '\n';
    }
    return 0;
}