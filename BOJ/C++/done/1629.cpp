#include <iostream>
using namespace std;
using ull = unsigned long long;
ull a, b, c, ans;
ull divide(ull a, ull b, ull c)
{
    if (b == 1)
        return a % c;

    if (b % 2 == 0)
        return divide(a, b / 2, c) * divide(a, b / 2, c) % c;
    else
        return (divide(a, b / 2, c) * divide(a, b / 2, c) % c) * a % c;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> a >> b >> c;

    ans = divide(a, b, c);
    cout << ans;
    return 0;
}