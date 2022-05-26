/**
 * https://www.acmicpc.net/problem/1158
 *
 * hint: queue를 활용해 해결
 */
#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    queue<int> q;
    string answer = "<";
    cin >> n;
    cin >> k;
    for (int i = 1; i <= n; i++)
        q.push(i);

    while (n--)
    {
        for (int i = 0; i < k; i++)
        {
            if (i == k - 1)
            {
                answer += to_string(q.front());
                q.pop();
            }
            else
            {
                q.push(q.front());
                q.pop();
            }
        }
        if (n > 0)
            answer += ", ";
    }
    answer += '>';
    cout << answer;
    return 0;
}
