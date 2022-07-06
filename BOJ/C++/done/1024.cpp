/**
 * https://www.acmicpc.net/problem/1024
 */
#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n, l;
    cin >> n >> l;
    while (l <= 100)
    {
        int candidate = n / l;
        for (int i = candidate - l + 1; i <= candidate; i++)
        {
            if (i < 0)
                continue;
            long long res = (l * (i + i + l - 1)) / 2;
            if (res == n)
            {
                for (int j = 0; j < l; j++)
                    cout << i + j << ' ';
                return 0;
            }
        }

        l++;
        if (l > 100)
            cout << -1;
    }

    return 0;
}