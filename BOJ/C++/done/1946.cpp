/**
 * https://www.acmicpc.net/problem/1946
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, docRank, intervRank, limit, cnt = 1;
        cin >> n;
        vector<pair<int, int>> scores;

        for (int i = 0; i < n; i++)
        {
            cin >> docRank >> intervRank;
            scores.push_back(make_pair(docRank, intervRank));
        }

        sort(scores.begin(), scores.end(), compare);

        limit = scores[0].second;
        for (int i = 1; i < scores.size(); i++)
        {
            intervRank = scores[i].second;
            if (limit > intervRank)
            {
                limit = intervRank;
                cnt++;
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}