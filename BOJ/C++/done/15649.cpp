#include <iostream>
using namespace std;

bool visited[10] = {false};
int answer[8] = {0};
void Permutation(int n, int m, int idx)
{
    if (idx == m)
    {
        for (int i = 0; i < m; i++)
            cout << answer[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
            continue;
        visited[i] = true;
        answer[idx] = i;
        Permutation(n, m, idx + 1);
        visited[i] = false;
        answer[idx] = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    Permutation(n, m, 0);
    return 0;
}