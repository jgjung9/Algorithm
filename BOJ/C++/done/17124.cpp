#include <iostream>
#include <algorithm>
using namespace std;
const int max_size = 1e6;
int t, n, m;
int a[max_size], b[max_size], c[max_size];

int search(int begin, int end, int target)
{
    int res, mid;
    mid = (begin + end) / 2;

    if (begin == mid)
    {
        int diff = 1e9;
        int pre = mid - 1, next = mid + 2;
        for (int i = pre; i <= next; i++)
        {
            if (i < 0 || i >= m)
                continue;
            if (diff > abs(b[i] - target))
            {
                diff = abs(b[i] - target);
                res = b[i];
            }
        }
        return res;
    }

    if (b[mid] > target)
        res = search(begin, mid - 1, target);
    else if (b[mid] < target)
        res = search(mid + 1, end, target);
    else
        res = b[mid];
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> t;
    while (t--)
    {
        unsigned long long ans = 0;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];
        sort(b, b + m);
        for (int i = 0; i < n; i++)
            ans += search(0, m - 1, a[i]);
        cout << ans << '\n';
    }
    return 0;
}