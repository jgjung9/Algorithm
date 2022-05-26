/**
 * https://www.acmicpc.net/problem/1874
 *
 * 스택
 */
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    bool isPossible = true;
    stack<int> s;
    string answer = "";
    int m = 0;
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        if (m < x)
        {
            while (m < x)
            {
                s.push(++m);
                answer += "+\n";
            }
            s.pop();
            answer += "-";
        }
        else
        {
            if (s.empty())
            {
                isPossible = false;
                break;
            }
            while (!s.empty())
            {
                int top = s.top();
                if (top < x)
                {
                    isPossible = false;
                    break;
                }
                if (top > x)
                {
                    s.pop();
                    answer += "-\n";
                }
                else
                {
                    s.pop();
                    answer += "-";
                    break;
                }
            }
            if (!isPossible)
                break;
        }

        if (n > 0)
            answer += '\n';
    }
    if (!isPossible)
        cout << "NO";
    else
        cout << answer;
    return 0;
}