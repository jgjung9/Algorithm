#include <iostream>
#include <queue>
using namespace std;
priority_queue<int> pq;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a, value;
    cin >> n;
    while (n--)
    {
        cin >> a;
        if (a == 0)
        {
            if (pq.empty())
                cout << -1 << '\n';
            else
            {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else
        {
            while (a--)
            {
                cin >> value;
                pq.push(value);
            }
        }
    }
    return 0;
}
