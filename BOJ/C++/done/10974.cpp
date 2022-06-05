/**
 * https://www.acmicpc.net/problem/10974
 *
 * solution: C++ STL next_permutation 함수를 이용한 간단한 풀이
 */
#include <iostream>
#include <algorithm>
using namespace std;
int permutation[8];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        permutation[i] = i + 1;
    do
    {
        for (int i = 0; i < n; i++)
            cout << permutation[i] << ' ';
        cout << '\n';
    } while (next_permutation(permutation, permutation + n));

    return 0;
}