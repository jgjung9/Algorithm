/**
 * https://www.acmicpc.net/problem/17413
 *
 * 스택을 이용한 단어 뒤집기
 */
#include <iostream>
#include <stack>
#include <string>
using namespace std;

string stackPrint(stack<char> &s)
{
    string str = "";
    while (!s.empty())
    {
        str += s.top();
        s.pop();
    }
    return str;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    stack<char> s;
    bool isTag = false;
    string answer = "";
    string str;
    getline(cin, str);
    for (char ch : str)
    {
        if (!isTag)
        {
            if (ch == '<')
            {
                isTag = true;
                answer += stackPrint(s);
                answer += ch;
            }
            else if (ch == ' ')
            {
                answer += stackPrint(s);
                answer += ch;
            }
            else
                s.push(ch);
        }
        else
        {
            if (ch == '>')
            {
                isTag = false;
                answer += ch;
            }
            else
                answer += ch;
        }
    }
    answer += stackPrint(s);
    cout << answer;
    return 0;
}
