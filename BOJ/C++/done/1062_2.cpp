/**
 * https://www.acmicpc.net/problem/1062
 *
 * solution: bitmask
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n, k, ans = 0;
vector<int> word;

void solve(int idx, int learn, int mask)
{
    if (idx == 'a' - 'a' || idx == 'n' - 'a' || idx == 't' - 'a' || idx == 'i' - 'a' || idx == 'c' - 'a')
    {
        solve(idx + 1, learn, mask);
        return;
    }

    if (learn == k)
    {
        int cnt = 0;
        int check = (1 << 26) - 1 - mask;
        for (int i = 0; i < word.size(); i++)
        {
            if ((word[i] & check) == 0)
                cnt++;
        }
        ans = max(ans, cnt);
        return;
    }

    if (idx == 26)
        return;

    solve(idx + 1, learn + 1, mask | (1 << idx));
    solve(idx + 1, learn, mask);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> k;
    int bitmask;
    for (int i = 0; i < n; i++)
    {
        bitmask = 0;
        string s;
        cin >> s;

        for (int j = 0; j < s.size(); j++)
            bitmask |= 1 << (s[j] - 'a');
        word.push_back(bitmask);
    }
    bitmask = 0;
    bitmask |= 1 << ('a' - 'a');
    bitmask |= 1 << ('n' - 'a');
    bitmask |= 1 << ('t' - 'a');
    bitmask |= 1 << ('i' - 'a');
    bitmask |= 1 << ('c' - 'a');
    if (k - 5 < 0)
    {
        cout << 0;
        return 0;
    }

    solve(0, 5, bitmask);
    cout << ans;
    return 0;
}