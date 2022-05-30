#include <iostream>
using namespace std;

int answer[8] = {0};
void repeatPermutationNonDesc(int n, int m, int idx)
{
    if (idx == m)
    {
        for (int i = 0; i < m; i++)
            cout << answer[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (idx > 0 && answer[idx - 1] > i)
            continue;
        answer[idx] = i;
        repeatPermutationNonDesc(n, m, idx + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    repeatPermutationNonDesc(n, m, 0);
    return 0;
}