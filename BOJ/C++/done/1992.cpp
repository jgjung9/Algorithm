#include <iostream>
#include <string>
using namespace std;
string s, ans = "";
int n;
int graph[64][64];

bool check(int x, int y, int length)
{
    int value = graph[x][y];
    for (int i = x; i < x + length; i++)
    {
        for (int j = y; j < y + length; j++)
        {
            if (graph[i][j] != value)
                return false;
        }
    }

    return true;
}
void divide(int x, int y, int length)
{
    if (check(x, y, length))
    {
        ans += to_string(graph[x][y]);
        return;
    }

    int q = length / 2;
    ans += '(';
    divide(x, y, q);
    divide(x, y + q, q);
    divide(x + q, y, q);
    divide(x + q, y + q, q);
    ans += ')';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < n; j++)
            graph[i][j] = s[j] - '0';
    }
    divide(0, 0, n);
    cout << ans;
    return 0;
}