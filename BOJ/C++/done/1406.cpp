/**
 * https://www.acmicpc.net/problem/1406
 *
 * hint: 스택을 활용해 해결
 */
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    stack<char> left, right;
    string str;
    int m;
    cin >> str;
    cin >> m;
    for (char ch : str)
        left.push(ch);

    while (m--)
    {
        char command;
        cin >> command;
        if (command == 'L' && left.size())
        {
            right.push(left.top());
            left.pop();
        }
        else if (command == 'D' && right.size())
        {
            left.push(right.top());
            right.pop();
        }
        else if (command == 'B' && left.size())
        {
            left.pop();
        }
        else if (command == 'P')
        {
            char ch;
            cin >> ch;
            left.push(ch);
        }
    }

    while (!left.empty())
    {
        right.push(left.top());
        left.pop();
    }

    while (!right.empty())
    {
        cout << right.top();
        right.pop();
    }

    return 0;
}