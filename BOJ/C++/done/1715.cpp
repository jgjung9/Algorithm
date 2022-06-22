/**
 * https://www.acmicpc.net/problem/1715
 *
 * solution: 최소 힙을 통한 그리디 알고리즘을 통한 해결
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, card, res, ans = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    cin >> n;
    while (n--)
    {
        cin >> card;
        pq.push(card);
    }

    while (!pq.empty())
    {
        res = pq.top();
        pq.pop();
        if (pq.empty())
            break;

        res += pq.top();
        pq.pop();
        pq.push(res);

        ans += res;
    }
    cout << ans;
    return 0;
}