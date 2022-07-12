#include <iostream>
using namespace std;
int n, maxValue = -1e9, minValue = 1e9;
int op[4] = {0};
int used[4] = {0};
int seq[11];

int calculate(int v1, int v2, int oper)
{
    if (oper == 0)
        return v1 + v2;
    else if (oper == 1)
        return v1 - v2;
    else if (oper == 2)
        return v1 * v2;
    else
        return v1 / v2;
}

void solve(int idx, int res)
{
    if (idx == n)
    {
        maxValue = max(maxValue, res);
        minValue = min(minValue, res);
        return;
    }

    if (idx == 0)
        solve(idx + 1, seq[0]);
    else
    {
        for (int i = 0; i < 4; i++)
        {
            if (used[i] < op[i])
            {
                used[i]++;
                solve(idx + 1, calculate(res, seq[idx], i));
                used[i]--;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> seq[i];

    for (int i = 0; i < 4; i++)
        cin >> op[i];

    solve(0, 0);
    cout << maxValue << '\n';
    cout << minValue;
    return 0;
}
