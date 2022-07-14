/**
 * https://www.acmicpc.net/problem/14889
 *
 * solution: 비트마스크를 이용한 풀이
 */
#include <iostream>
#include <vector>
using namespace std;
int n, ans = 1e9;
int s[20][20];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> s[i][j];

    for (int i = 0; i < (1 << n); i++)
    {
        vector<int> start, link;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
                start.push_back(j);
            else
                link.push_back(j);
        }
        if (start.size() != n / 2)
            continue;
        int startSum = 0, linkSum = 0;
        for (int j = 0; j < start.size(); j++)
        {
            for (int k = 0; k < start.size(); k++)
            {
                if (j == k)
                    continue;
                startSum += s[start[j]][start[k]];
                linkSum += s[link[j]][link[k]];
            }
        }
        ans = min(ans, abs(startSum - linkSum));
    }

    cout << ans;
    return 0;
}