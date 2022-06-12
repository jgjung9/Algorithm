#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, ans = 0;
    int a[50], b[50];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    sort(a, a + n);
    sort(b, b + n);
    for (int i = 0; i < n; i++)
        ans += a[i] * b[n - i - 1];
    cout << ans;
    return 0;
}