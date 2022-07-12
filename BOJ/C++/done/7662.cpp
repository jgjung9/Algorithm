/**
 * https://www.acmicpc.net/problem/7662
 *
 */
#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
int t, k, value;
char command;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> t;
    while (t--)
    {
        priority_queue<int, vector<int>, greater<int>> minQ;
        priority_queue<int> maxQ;
        map<int, int> m;

        cin >> k;
        for (int i = 0; i < k; i++)
        {
            cin >> command >> value;

            if (command == 'D')
            {
                if (value == 1)
                {
                    while (!maxQ.empty() && m.find(maxQ.top()) == m.end())
                        maxQ.pop();
                    if (maxQ.empty())
                        continue;
                    int del = maxQ.top();
                    maxQ.pop();
                    auto it = m.find(del);
                    if (it->second == 1)
                        m.erase(del);
                    else
                        it->second--;
                }
                else
                {
                    while (!minQ.empty() && m.find(minQ.top()) == m.end())
                        minQ.pop();
                    if (minQ.empty())
                        continue;
                    int del = minQ.top();
                    minQ.pop();
                    auto it = m.find(del);
                    if (it->second == 1)
                        m.erase(del);
                    else
                        it->second--;
                }
            }
            else if (command == 'I')
            {
                m[value]++;
                maxQ.push(value);
                minQ.push(value);
            }
        }

        while (!maxQ.empty() && m.find(maxQ.top()) == m.end())
            maxQ.pop();
        while (!minQ.empty() && m.find(minQ.top()) == m.end())
            minQ.pop();

        if (minQ.empty() || maxQ.empty())
            cout << "EMPTY\n";
        else
            cout << maxQ.top() << ' ' << minQ.top() << '\n';
    }

    return 0;
}