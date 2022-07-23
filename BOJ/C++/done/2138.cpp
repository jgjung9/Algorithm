/**
 * https://www.acmicpc.net/problem/2138
 *
 * soultion: Greedy
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int n, ans = -1;
string str;
vector<int> state1, state2, target;

void change(int idx, vector<int> &lights)
{
    for (int i = idx - 1; i <= idx + 1; i++)
    {
        if (i < n)
            lights[i] = 1 - lights[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n;
    cin >> str;
    for (int i = 0; i < n; i++)
    {
        state1.push_back(str[i] - '0');
        state2.push_back(str[i] - '0');
    }
    cin >> str;
    for (int i = 0; i < n; i++)
        target.push_back(str[i] - '0');

    int cnt = 0;
    for (int i = 1; i < n; i++)
    {
        if (state1[i - 1] != target[i - 1])
        {
            change(i, state1);
            cnt++;
        }
    }
    if (state1[n - 1] == target[n - 1])
        ans = cnt;
    cnt = 1;
    state2[0] = 1 - state2[0];
    state2[1] = 1 - state2[1];
    for (int i = 1; i < n; i++)
    {
        if (state2[i - 1] != target[i - 1])
        {
            change(i, state2);
            cnt++;
        }
    }
    if (state2[n - 1] == target[n - 1])
        ans = (ans == -1) ? cnt : min(ans, cnt);
    cout << ans;
    return 0;
}