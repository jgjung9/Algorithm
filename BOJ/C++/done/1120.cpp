#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string a, b;
    int ans = 50, diff;
    cin >> a >> b;

    for (int i = 0; i <= b.size() - a.size(); i++)
    {
        diff = 0;
        for (int j = 0; j < a.size(); j++)
        {
            if (a[j] != b[i + j])
                diff++;
        }
        ans = min(ans, diff);
    }
    cout << ans;
    return 0;
}