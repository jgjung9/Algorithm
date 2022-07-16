/**
 * https://www.acmicpc.net/problem/12865
 *
 * solution:
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, k, w, v;
vector<pair<int, int>> items;
int d[101][100001] = {0};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> w >> v;
        items.push_back(make_pair(w, v));
    }
    sort(items.begin(), items.end());

    for (int i = 0; i < items.size(); i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (items[i].first <= j)
                d[i + 1][j] = max(d[i][j], d[i][j - items[i].first] + items[i].second);
            else
                d[i + 1][j] = d[i][j];
        }
    }
    cout << d[n][k];
    return 0;
}