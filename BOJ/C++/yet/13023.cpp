/**
 * https://www.acmicpc.net/problem/13023
 *
 * solution:
 */
#include <iostream>
#include <vector>
using namespace std;

vector<int> v[2000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int from, to;
        cin >> from >> to;
        v[from].push_back(to);
        v[to].push_back(from);
    }

    cout << 0;

    return 0;
}
