#include <iostream>
#include <string>
using namespace std;
string s;
int n, m, p, ans = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> s;

    int end = m - (2 * n + 1);
    for (int i = 0; i <= end; i++)
    {
        if (s[i] == 'O')
            continue;

        p = 0;
        while (s[i + 1] == 'O' && s[i + 2] == 'I')
        {
            p++;
            if (p == n)
            {
                ans++;
                p--;
            }
            i += 2;
        }
    }
    cout << ans;
    return 0;
}