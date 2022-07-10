/**
 * https://www.acmicpc.net/problem/1793
 *
 */
#include <iostream>
using namespace std;
int n;
unsigned long long d[251] = {0};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    d[0] = d[1] = 1;
    for (int i = 2; i < 251; i++)
        d[i] = d[i - 1] + 2 * d[i - 2];
    return 0;
}