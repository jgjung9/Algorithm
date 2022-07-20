/**
 * https://www.acmicpc.net/problem/2961
 *
 * solution: bitmask
 */
#include <iostream>
#include <vector>
using namespace std;
int n, s, b, ans = 1e9;
vector<pair<int, int>> ingredients;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s >> b;
        ingredients.push_back(make_pair(s, b));
    }

    for (int i = 1; i < (1 << n); i++)
    {
        vector<pair<int, int>> used;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
                used.push_back(ingredients[j]);
        }
        s = 1, b = 0;
        for (int j = 0; j < used.size(); j++)
        {
            s *= used[j].first;
            b += used[j].second;
        }
        ans = min(ans, abs(s - b));
    }
    cout << ans;
    return 0;
}