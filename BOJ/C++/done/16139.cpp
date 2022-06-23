#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<vector<int>> d(26, vector<int>(200000, 0));

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    int q, l, r;
    char a;
    cin >> s >> q;
    for (int i = 0; i < s.size(); i++)
    {
        int idx = s[i] - 'a';
        if (i == 0)
        {
            d[idx][i] = 1;
            continue;
        }

        for (int j = 0; j < 26; j++)
        {
            if (j == idx)
                d[j][i] = d[j][i - 1] + 1;
            else
                d[j][i] = d[j][i - 1];
        }
    }
    while (q--)
    {
        cin >> a >> l >> r;
        int idx = a - 'a';
        if (l == 0)
            cout << d[idx][r] << '\n';
        else
            cout << d[idx][r] - d[idx][l - 1] << '\n';
    }
    return 0;
}