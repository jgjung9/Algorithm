#include <iostream>
#include <vector>
using namespace std;
long long mi, ma;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int ans = 0;
    cin >> mi >> ma;
    vector<bool> visited(ma - mi + 1, false);
    for (long long i = 2; i * i <= ma; i++)
    {
        long long squre = i * i;
        long long start = (mi / squre) * squre;
        start = start < mi ? start + squre : start;
        for (long long j = start; j <= ma; j += squre)
        {
            visited[j - mi] = true;
        }
    }
    for (int i = 0; i < visited.size(); i++)
    {
        if (!visited[i])
            ans++;
    }
    cout << ans;
    return 0;
}