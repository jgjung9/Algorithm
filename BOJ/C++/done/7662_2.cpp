#include <iostream>
#include <vector>
#include <queue>
#include <set>
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
        multiset<int> ms;

        cin >> k;
        for (int i = 0; i < k; i++)
        {
            cin >> command >> value;
            if (command == 'D')
            {
                if (value == 1)
                {
                    while (!maxQ.empty() && ms.find(maxQ.top()) == ms.end())
                        maxQ.pop();
                    if (maxQ.empty())
                        continue;
                    int del = maxQ.top();
                    auto it = ms.find(del);
                    ms.erase(it);
                }
                else
                {
                    while (!minQ.empty() && ms.find(minQ.top()) == ms.end())
                        minQ.pop();
                    if (minQ.empty())
                        continue;
                    int del = minQ.top();
                    auto it = ms.find(del);
                    ms.erase(it);
                }
            }
            else
            {
                ms.insert(value);
                maxQ.push(value);
                minQ.push(value);
            }
        }
        while (!maxQ.empty() && ms.find(maxQ.top()) == ms.end())
            maxQ.pop();
        while (!minQ.empty() && ms.find(minQ.top()) == ms.end())
            minQ.pop();

        if (minQ.empty() || maxQ.empty())
            cout << "EMPTY\n";
        else
            cout << maxQ.top() << ' ' << minQ.top() << '\n';
    }
    return 0;
}