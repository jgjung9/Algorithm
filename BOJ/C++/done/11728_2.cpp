#include <iostream>
#include <vector>
using namespace std;
int n, m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m;
    vector<int> a(n), b(m), ans;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    int l = 0, r = 0;
    while (l < n && r < m)
    {
        if (a[l] < b[r])
            ans.push_back(a[l++]);
        else
            ans.push_back(b[r++]);
    }
    while (l < n)
        ans.push_back(a[l++]);
    while (r < m)
        ans.push_back(b[r++]);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';
    return 0;
}