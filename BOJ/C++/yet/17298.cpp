/**
 * https://www.acmicpc.net/problem/17298
 *
 *
 */
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> seq(n, 0);
    vector<int> nge(n, -1);
    stack<int> s;
    for (int i = 0; i < n; i++)
        cin >> seq[i];

    s.push(seq[0]);
    for (int i = 1; i < n; i++)
    {
        if (s.top() < seq[i])
        {
            int temp = i;
            while (!s.empty() && !(s.top() > seq[i]))
            {
                s.pop();
                temp--;
                nge[temp] = seq[i];
            }
            s.push(seq[i]);
        }
        else
            s.push(seq[i]);
    }

    for (int i = 0; i < n; i++)
        cout << nge[i] << ' ';
    return 0;
}