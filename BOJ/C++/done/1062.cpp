/**
 * https://www.acmicpc.net/problem/1062
 *
 * solution: 비트마스크 antic
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int n, k, ans = 0;
vector<char> alphabet;
vector<string> word;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        word.push_back(str);
        for (int j = 0; j < str.size(); j++)
        {
            if (str[j] == 'a' || str[j] == 'n' || str[j] == 't' || str[j] == 'c' || str[j] == 'i')
                continue;
            alphabet.push_back(str[j]);
        }
    }
    sort(alphabet.begin(), alphabet.end());
    alphabet.erase(unique(alphabet.begin(), alphabet.end()), alphabet.end());

    if (static_cast<int>(alphabet.size()) <= k - 5)
    {
        cout << n;
        return 0;
    }
    for (int i = 0; i < (1 << alphabet.size()); i++)
    {
        int cnt = 0;
        vector<char> used;
        for (int j = 0; j < alphabet.size(); j++)
        {
            if (i & (1 << j))
                used.push_back(alphabet[j]);
        }

        if (used.size() != k - 5)
            continue;

        for (string s : word)
        {
            bool ok = true;
            for (int j = 0; j < s.size(); j++)
            {
                if (s[j] == 'a' || s[j] == 'n' || s[j] == 't' || s[j] == 'c' || s[j] == 'i')
                    continue;

                bool isPossible = false;
                for (int index = 0; index < used.size(); index++)
                {
                    if (s[j] == used[index])
                    {
                        isPossible = true;
                        break;
                    }
                }
                if (!isPossible)
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
                cnt++;
        }
        ans = max(ans, cnt);
    }
    cout << ans;
    return 0;
}