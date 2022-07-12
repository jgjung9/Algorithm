/**
 * https://www.acmicpc.net/problem/2529
 *
 * solution: 백트래킹
 * 차례대로 수를 넣어보고 조건을 만족하지 않을경우 제외하는 방식으로 진행
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int k, maxAns = 0, minAns = 1e9;
string res;
char op[9];
bool visited[10] = {false};
vector<string> ans;

bool check(int value, int pre, int idx)
{
    if (idx == -1)
        return true;

    if (op[idx] == '<')
        return pre < value;
    else
        return pre > value;
}

void solve(int idx, int pre)
{
    if (idx == k + 1)
    {
        ans.push_back(res);
        return;
    }

    for (int i = 0; i < 10; i++)
    {
        if (visited[i])
            continue;
        if (check(i, pre, idx - 1))
        {
            visited[i] = true;
            res += to_string(i);
            solve(idx + 1, i);
            visited[i] = false;
            res = res.substr(0, res.size() - 1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> k;
    for (int i = 0; i < k; i++)
        cin >> op[i];

    solve(0, -1);
    cout << ans.back() << '\n';
    cout << ans.front();
    return 0;
}