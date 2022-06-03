/**
 * https://www.acmicpc.net/problem/1269
 *
 * solution: 대칭 차집합
 * A + B - A ∩ B
 */
#include <iostream>
#include <set>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b, n;
    cin >> a >> b;
    set<int> A;
    set<int> B;
    int ans = 0;
    while (a--)
    {
        cin >> n;
        A.insert(n);
    }
    while (b--)
    {
        cin >> n;
        B.insert(n);
    }
    for (auto it = A.begin(); it != A.end(); it++)
    {
        if (!B.count(*it))
            ans++;
    }
    for (auto it = B.begin(); it != B.end(); it++)
    {
        if (!A.count(*it))
            ans++;
    }

    cout << ans;
    return 0;
}