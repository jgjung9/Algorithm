#include <iostream>
using namespace std;
int n, s, ans = 0;
int seq[20];

void solve(int idx, int cnt, int res)
{
    if (idx == n)
    {
        if (cnt > 0 && res == s)
            ans++;
        return;
    }
    solve(idx + 1, cnt + 1, res + seq[idx]);
    solve(idx + 1, cnt, res);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cin >> seq[i];
    solve(0, 0, 0);
    cout << ans;
    return 0;
}