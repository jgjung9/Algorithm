#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;
const int MAX_VALUE = 1e9;

void action(vector<int> &input, vector<pair<string, int>> &commands)
{
    for (int i = 0; i < input.size(); i++)
    {
        stack<ll> s;
        s.push(input[i]);
        bool err = false;

        for (int j = 0; j < commands.size(); j++)
        {
            string com = commands[j].first;
            int value = commands[j].second;

            if (com == "NUM")
                s.push(value);
            else if (com == "POP")
            {
                if (s.empty())
                {
                    err = true;
                    break;
                }
                s.pop();
            }
            else if (com == "INV")
            {
                if (s.empty())
                {
                    err = true;
                    break;
                }
                ll tmp = s.top();
                s.pop();
                s.push(-tmp);
            }
            else if (com == "DUP")
            {
                if (s.empty())
                {
                    err = true;
                    break;
                }
                s.push(s.top());
            }
            else if (com == "SWP")
            {
                if (s.size() < 2)
                {
                    err = true;
                    break;
                }
                ll first, second;
                first = s.top(), s.pop();
                second = s.top(), s.pop();
                s.push(first);
                s.push(second);
            }
            else if (com == "ADD")
            {
                if (s.size() < 2)
                {
                    err = true;
                    break;
                }
                ll first, second;
                first = s.top(), s.pop();
                second = s.top(), s.pop();
                if (MAX_VALUE < abs(first + second))
                {
                    err = true;
                    break;
                }
                s.push(first + second);
            }
            else if (com == "SUB")
            {
                if (s.size() < 2)
                {
                    err = true;
                    break;
                }
                ll first, second;
                first = s.top(), s.pop();
                second = s.top(), s.pop();
                if (MAX_VALUE < abs(second - first))
                {
                    err = true;
                    break;
                }
                s.push(second - first);
            }
            else if (com == "MUL")
            {
                if (s.size() < 2)
                {
                    err = true;
                    break;
                }
                ll first, second;
                first = s.top(), s.pop();
                second = s.top(), s.pop();
                if (MAX_VALUE < abs(first * second))
                {
                    err = true;
                    break;
                }
                s.push(first * second);
            }
            else if (com == "DIV")
            {
                if (s.size() < 2)
                {
                    err = true;
                    break;
                }
                ll first, second;
                first = s.top(), s.pop();
                second = s.top(), s.pop();
                if (first == 0)
                {
                    err = true;
                    break;
                }
                s.push(second / first);
            }
            else if (com == "MOD")
            {
                if (s.size() < 2)
                {
                    err = true;
                    break;
                }
                ll first, second;
                first = s.top(), s.pop();
                second = s.top(), s.pop();
                if (first == 0)
                {
                    err = true;
                    break;
                }
                s.push(second % first);
            }
        }

        if (err || s.size() != 1)
            cout << "ERROR\n";
        else
            cout << s.top() << '\n';
    }
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    while (true)
    {
        vector<pair<string, int>> commands;
        vector<int> input;
        string command;
        while (true)
        {
            int t, value;
            cin >> command;

            if (command == "QUIT")
                return 0;
            if (command == "END")
            {
                cin >> t;
                for (int i = 0; i < t; i++)
                {
                    cin >> value;
                    input.push_back(value);
                }
                break;
            }
            else if (command == "NUM")
            {
                cin >> value;
                commands.push_back(make_pair(command, value));
            }
            else
                commands.push_back(make_pair(command, 0));
        }

        action(input, commands);
    }
}