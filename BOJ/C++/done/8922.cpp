#include <iostream>
using namespace std;
int s[15];

bool check(int n)
{
    for (int i = 0; i < n; i++)
    {
        if (s[i] > 0)
            return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, n, cnt;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cnt = 0;
        for (int i = 0; i < n; i++)
            cin >> s[i];

        while (!check(n) && cnt < 1000)
        {
            int temp = s[0];
            for (int i = 0; i < n; i++)
            {
                if (i == n - 1)
                    s[i] = abs(s[i] - temp);
                else
                    s[i] = abs(s[i] - s[i + 1]);
            }
            cnt++;
        }
        if (cnt == 1000)
            cout << "LOOP" << '\n';
        else
            cout << "ZERO" << '\n';
    }
    return 0;
}