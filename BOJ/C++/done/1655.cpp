#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    priority_queue<int> left, right;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        i % 2 == 0 ? left.push(k) : right.push(-k);
        if (i > 0 && left.top() > -right.top())
        {
            int l = left.top();
            int r = -right.top();
            left.pop();
            right.pop();
            left.push(r);
            right.push(-l);
        }
        cout << left.top() << '\n';
    }
    return 0;
}