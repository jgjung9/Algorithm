#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    int start = static_cast<int>(sqrt(m));
    int minValue = 10000;
    int sum = 0;
    for (int i = start; i * i <= n; i++)
    {
        int squre = i * i;
        if (squre < m)
            continue;
        else
        {
            minValue = min(minValue, squre);
            sum += squre;
        }
    }
    if (sum == 0)
        cout << -1;
    else
    {
        cout << sum << '\n';
        cout << minValue;
    }
    return 0;
}