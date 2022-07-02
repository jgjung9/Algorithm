/**
 * https://www.acmicpc.net/problem/7662
 *
 * solution: 이중우선순위 큐
 */
#include <iostream>
#include <queue>
using namespace std;
int t, k, n;
char com;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--)
    {
        priority_queue<int> minq, maxq;
        cin >> k;
        while (k--)
        {
            cin >> com >> n;
            if (com == 'I')
            {
                minq.push(-n);
                maxq.push(n);
            }
            else if (com == 'D')
            {
                if (minq.empty() || maxq.empty() || -minq.top() > maxq.top())
                    continue;
                if (n == -1)
                    minq.pop();
                else
                    maxq.pop();
            }
        }
        if (minq.empty() || maxq.empty() || -minq.top() > maxq.top())
            cout << "EMPTY" << '\n';
        else
            cout << maxq.top() << ' ' << -minq.top() << '\n';
    }

    return 0;
}