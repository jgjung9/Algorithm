/**
 * https://www.acmicpc.net/problem/12865
 *
 * solution: DP(동적 계획법)을 활용한 배낭 문제
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int d[100001] = {0};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k, w, v;
    vector<pair<int, int>> items;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> w >> v;
        items.push_back(make_pair(w, v));
    }

    for (int i = 1; i <= k; i++)
    {
        for (int j = 0; j < items.size(); j++)
        {
            tie(w, v) = items[j];
            if (i - w < 0)
                continue;
            d[i] = max(d[i], d[i - w] + v);
        }
    }
    return 0;
}