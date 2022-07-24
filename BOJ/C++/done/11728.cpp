/**
 * https://www.acmicpc.net/problem/11728
 *
 * solution: sort 함수활용 or 투포인터를 활용한 머지
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> res;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n, m, v;
    cin >> n >> m;
    for (int i = 0; i < n + m; i++)
    {
        cin >> v;
        res.push_back(v);
    }
    sort(res.begin(), res.end());
    for (int i = 0; i < n + m; i++)
        cout << res[i] << ' ';
    return 0;
}