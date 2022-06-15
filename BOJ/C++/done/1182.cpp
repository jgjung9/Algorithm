#include <iostream>
using namespace std;
int n, s, cnt = 0, ans = 0;
int seq[20];

void check(int n, int idx)
{
    if (n == idx)
    {
        cnt = (ans == s ? cnt + 1 : cnt);
        return;
    }

    ans += seq[idx];
    check(n, idx + 1);
    ans -= seq[idx];
    check(n, idx + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cin >> seq[i];
    check(n, 0);
    if (s == 0)
        cout << cnt - 1;
    else
        cout << cnt;

    return 0;
}