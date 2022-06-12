#include <iostream>
#include <vector>
using namespace std;
vector<int> s(100001, 0);
vector<int> sum(1000001, 0);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k, res = -1e9;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        sum[i] = sum[i - 1] + s[i];
    }
    for (int i = k; i <= n; i++)
        res = max(res, sum[i] - sum[i - k]);
    cout << res;
    return 0;
}