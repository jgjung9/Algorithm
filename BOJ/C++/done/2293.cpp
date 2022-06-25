#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k, value, coins[100], d[10001] = {0};
    cin >> n >> k;

    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        if (value <= k)
            coins[idx++] = value;
    }

    d[0] = 1;
    for (int i = 0; i < idx; i++)
    {
        for (int j = 0; j <= k - coins[i]; j++)
            d[j + coins[i]] += d[j];
    }

    cout << d[k];
    return 0;
}