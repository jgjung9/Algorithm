/**
 * https://www.acmicpc.net/problem/1339
 *
 * solution: 브루트 포스(Brute Force)
 * 알파벳 최대 10개를 중복 없이 0 ~ 9 까지를 부여하는 경우의 수는
 * 10! -> 약 360만 시간제한 2초로 충분히 해결가능한 범위
 * 모든 경우를 순회하며, 최대값을 찾아 반환한다.
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n, ans;
string word[10];
vector<char> alphabet;
bool visited[10] = {0};
int value[26];

int calculate()
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int res = 0;
        for (int j = 0; j < word[i].size(); j++)
            res = res * 10 + value[word[i][j] - 'A'];
        sum += res;
    }
    return sum;
}

void solve(int idx)
{
    if (idx == alphabet.size())
    {
        ans = max(ans, calculate());
        return;
    }

    for (int i = 9; i > 9 - static_cast<int>(alphabet.size()); i--)
    {
        if (visited[i])
            continue;
        value[alphabet[idx] - 'A'] = i;
        visited[i] = true;
        solve(idx + 1);
        value[alphabet[idx] - 'A'] = 0;
        visited[i] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> word[i];
        for (int j = 0; j < word[i].size(); j++)
            alphabet.push_back(word[i][j]);
    }
    sort(alphabet.begin(), alphabet.end());
    alphabet.erase(unique(alphabet.begin(), alphabet.end()), alphabet.end());

    solve(0);
    cout << ans;
    return 0;
}
