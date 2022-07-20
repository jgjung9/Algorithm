/**
 * https://www.acmicpc.net/problem/15661
 *
 * solution: bitmask
 */
#include <iostream>
#include <vector>
using namespace std;
int n, ans = 1e9;
int ability[20][20];

void solve()
{
    for (int i = 0; i < (1 << n); i++)
    {
        vector<int> start, link;
        int startAbility = 0, linkAbility = 0;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
                start.push_back(j);
            else
                link.push_back(j);
        }
        for (int i = 0; i < start.size(); i++)
            for (int j = 0; j < start.size(); j++)
                startAbility += ability[start[i]][start[j]];
        for (int i = 0; i < link.size(); i++)
            for (int j = 0; j < link.size(); j++)
                linkAbility += ability[link[i]][link[j]];

        ans = min(ans, abs(startAbility - linkAbility));
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> ability[i][j];
    solve();
    cout << ans;
    return 0;
}