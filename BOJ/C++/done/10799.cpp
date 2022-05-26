/*
 * https://www.acmicpc.net/problem/10799
 *
 * hint: 스택을 이용해 문제 풀이를 할 수 있다.
 */
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string str;
    stack<char> s;
    char pre = ' ';
    cin >> str;
    int count = 0;
    for (char ch : str)
    {
        if (ch == '(')
        {
            s.push(ch);
        }
        else
        {
            if (pre == '(')
            {
                s.pop();
                count += s.size();
            }
            else
            {
                s.pop();
                count++;
            }
        }

        pre = ch;
    }
    cout << count;
    return 0;
}