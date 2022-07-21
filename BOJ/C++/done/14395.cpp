/**
 * https://www.acmicpc.net/problem/14395
 *
 * solution: BFS
 * 점을 방문할 경우 set에 넣어 방문 여부를 기록한다.
 * 방문한 점은 재방문하지 않는다
 * 방문 순서는 * + - / 순서로진행한다.
 * 큐에 방문하는 점과 그 점에 도달하는데 사용한 연산을 기록한다.
 * 타겟에 도착하면 사용된 연산을 출력하고 종료한다.
 * BFS가 끝날 때까지 타겟에 도달하지 못하면 -1을 출력하고 종료한다.
 */
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
using namespace std;
using ll = long long;
ll s, t;
set<ll> visited;
char oper[4] = {'*', '+', '-', '/'};

ll calculate(ll value, int op)
{
    if (op == 0)
        return value * value;
    else if (op == 1)
        return value + value;
    else if (op == 2)
        return 0;
    else
        return 1;
}

void BFS(ll node)
{
    queue<pair<ll, string>> q;
    string ans = "";
    visited.insert(node);
    q.push(make_pair(node, ans));

    while (!q.empty())
    {
        node = q.front().first, ans = q.front().second;
        q.pop();

        if (node == t)
        {
            cout << ans;
            return;
        }

        for (int dir = 0; dir < 4; dir++)
        {
            ll nextNode;
            if (dir != 3)
                nextNode = calculate(node, dir);
            else
            {
                if (node == 0)
                    continue;
                else
                    nextNode = calculate(node, dir);
            }
            if (nextNode < 0 || nextNode > 1e9)
                continue;
            if (visited.find(nextNode) != visited.end())
                continue;
            visited.insert(nextNode);
            q.push(make_pair(nextNode, ans + oper[dir]));
        }
    }
    cout << -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> s >> t;

    if (s == t)
    {
        cout << 0;
        return 0;
    }

    BFS(s);
    return 0;
}