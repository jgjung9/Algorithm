#include <iostream>
#include <algorithm>
using namespace std;

int input[10] = {0};
int answer[10] = {0};
void Permutation(int n, int m, int idx)
{
    if (idx == m)
    {
        for (int i = 0; i < m; i++)
            cout << answer[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 0; i < n; i++)
    {
        answer[idx] = input[i];
        Permutation(n, m, idx + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> input[i];
    sort(input, input + n);
    Permutation(n, m, 0);
    return 0;
}