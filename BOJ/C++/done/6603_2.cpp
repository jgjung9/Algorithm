// 백트래킹 구현
#include <iostream>
using namespace std;
int k;
int s[12];
int ans[6];
bool visited[12] = {0};

void solve(int idx)
{
    if (idx == 6)
    {
        for (int i = 0; i < 6; i++)
            cout << ans[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = 0; i < k; i++)
    {
        if (visited[i])
            continue;
        if (idx && ans[idx - 1] > s[i])
            continue;
        visited[i] = true;
        ans[idx] = s[i];
        solve(idx + 1);
        visited[i] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    while (true)
    {
        cin >> k;
        if (k == 0)
            break;
        for (int i = 0; i < k; i++)
            cin >> s[i];
        solve(0);
        cout << '\n';
    }
    return 0;
}