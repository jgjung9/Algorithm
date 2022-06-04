/**
 * https://www.acmicpc.net/problem/10972
 *
 * solution: C++ STL에 있는 next_permutation함수를 이용한 간단한 풀이
 */

#include <iostream>
#include <algorithm>
using namespace std;
int permutation[10000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> permutation[i];
    if (next_permutation(permutation, permutation + n))
    {
        for (int i = 0; i < n; i++)
            cout << permutation[i] << ' ';
    }
    else
        cout << -1;
    return 0;
}