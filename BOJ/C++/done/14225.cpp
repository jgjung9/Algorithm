#include <iostream>
#include <set>
using namespace std;
int n;
int seq[20];
set<int> res;

void solve(int idx, int sum)
{
    if (idx == n)
    {
        res.insert(sum);
        return;
    }

    solve(idx + 1, sum + seq[idx]);
    solve(idx + 1, sum);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> seq[i];

    solve(0, 0);
    for (int i = 1;; i++)
    {
        if (res.find(i) == res.end())
        {
            cout << i;
            break;
        }
    }
    return 0;
}