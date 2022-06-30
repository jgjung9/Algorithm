/**
 * https://www.acmicpc.net/problem/14226
 *
 * solution: BFS를 해당 이모티콘의 개수에 도출
 * 이모티콘의 개수가 목표치에 도달하면 BFS를 종료하고 정답을 출력한다.
 */
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
const int MAX_SIZE = 1001;
int visited[MAX_SIZE][MAX_SIZE] = {0};
int s, ans;

void BFS(int cnt, int depth)
{
    int clip = 0;
    queue<tuple<int, int, int>> q;
    visited[cnt][clip] = depth;
    q.push(make_tuple(cnt, clip, depth));

    while (!q.empty())
    {
        tie(cnt, clip, depth) = q.front();
        q.pop();
        for (int i = 0; i < 3; i++)
        {
            int nextCnt, nextDep, nextClip;
            if (i == 0)
            {
                nextCnt = cnt;
                nextDep = depth + 1;
                nextClip = cnt;
            }
            else if (i == 1)
            {
                nextCnt = cnt + clip;
                nextDep = depth + 1;
                nextClip = clip;
            }
            else
            {
                nextCnt = cnt - 1;
                nextDep = depth + 1;
                nextClip = clip;
            }
            if (nextCnt <= 0 || nextCnt >= MAX_SIZE)
                continue;
            if (visited[nextCnt][nextClip])
                continue;

            if (nextCnt == s)
            {
                ans = nextDep - 1;
                return;
            }
            visited[nextCnt][nextClip] = nextDep;
            q.push(make_tuple(nextCnt, nextClip, nextDep));
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s;
    BFS(1, 1);
    cout << ans;
    return 0;
}