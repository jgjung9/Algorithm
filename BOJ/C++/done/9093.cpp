#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string str;
        getline(cin, str);
        str += '\n';
        stack<char> s;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == ' ' || str[i] == '\n')
            {
                while (!s.empty())
                {
                    cout << s.top();
                    s.pop();
                }
                cout << str[i];
            }

            else
                s.push(str[i]);
        }
    }

    return 0;
}