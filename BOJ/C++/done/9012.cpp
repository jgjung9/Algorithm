#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        bool isPossible = true;
        stack<char> s;
        string str;
        cin >> str;
        for (int i = 0; i < str.size(); i++)
        {
            if (!isPossible)
                break;
            if (str[i] == '(')
                s.push(str[i]);
            else if (s.size() > 0)
                s.pop();
            else
                isPossible = false;
        }
        if (s.size() > 0)
            isPossible = false;
        if (isPossible)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}