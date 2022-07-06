/**
 * https://www.acmicpc.net/problem/3613
 *
 */
#include <iostream>
#include <string>
using namespace std;

bool checkJava(string s)
{
    if (s[0] == toupper(s[0]))
        return false;

    for (int i = 0; i < s.size(); i++)
        if (s[i] == '_')
            return false;
    return true;
}

bool checkCpp(string s)
{
    if (s[0] == '_' || s[0] == toupper(s[0]) || s[s.size() - 1] == '_')
        return false;

    char pre = s[0];
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == '_' && pre == s[i])
            return false;
        if (s[i] != '_' && s[i] == toupper(s[i]))
            return false;
        pre = s[i];
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    string s, ans;
    cin >> s;

    if (checkJava(s))
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == toupper(s[i]))
            {
                ans += '_';
                ans += tolower(s[i]);
            }
            else
                ans += s[i];
        }
    }
    else if (checkCpp(s))
    {
        bool isUpper = false;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '_')
                isUpper = true;
            else if (isUpper)
            {
                ans += toupper(s[i]);
                isUpper = false;
            }
            else
                ans += s[i];
        }
    }
    else
    {
        cout << "Error!";
        return 0;
    }
    cout << ans;
    return 0;
}