#include <iostream>
#include <deque>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n, m, v, ans = 0;
    cin >> n >> m;
    deque<int> dq;
    for (int i = 1; i <= n; i++)
        dq.push_back(i);

    for (int i = 0; i < m; i++)
    {
        cin >> v;
        int left = 0, right = 0;
        for (auto it = dq.begin(); it != dq.end(); ++it)
        {
            if (*it == v)
                break;
            left++;
        }

        for (auto it = dq.rbegin(); it != dq.rend(); ++it)
        {
            if (*it == v)
                break;
            right++;
        }

        if (left <= right)
        {
            for (int j = 0; j < left; j++)
            {
                int value = dq.front();
                dq.push_back(value);
                dq.pop_front();
            }
            ans += left;
        }
        else
        {
            for (int j = 0; j <= right; j++)
            {
                int value = dq.back();
                dq.push_front(value);
                dq.pop_back();
            }
            ans += right + 1;
        }
        dq.pop_front();
    }
    cout << ans;
    return 0;
}