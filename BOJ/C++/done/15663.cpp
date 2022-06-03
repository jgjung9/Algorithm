/**
 * https://www.acmicpc.net/problem/15663
 *
 */
#include <iostream>
#include <algorithm>
using namespace std;
int number[8] = {0};
int answer[8] = {0};
bool visited[8] = {false};

void Permutation(int n, int m, int idx)
{
    if (m == idx)
    {
        for (int i = 0; i < m; i++)
            cout << answer[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (visited[i])
            continue;
        if (answer[idx] == number[i])
            continue;
        visited[i] = true;
        answer[idx] = number[i];
        Permutation(n, m, idx + 1);
        visited[i] = false;
    }
    answer[idx] = 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> number[i];
    sort(number, number + n);
    Permutation(n, m, 0);
    return 0;
}