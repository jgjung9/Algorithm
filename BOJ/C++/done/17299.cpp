/**
 * https://www.acmicpc.net/problem/17299
 *
 * hint: 값을 입력받고 입력받은 값의 빈도를 저장한다.
 * 빈도를 비교해 해당 오른쪽에서 처음으로 자신의 빈도보다 큰 빈도가 나온 첫 값을
 * 오등큰수로 저장한다. 스택을 활용하여 진행
 */
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
const int MAX_SIZE = 1000001;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> seq(n);
    vector<int> freq(MAX_SIZE, 0);
    vector<int> ngf(n, -1);
    stack<vector<int>> s;
    for (int i = 0; i < n; i++)
    {
        cin >> seq[i];
        freq[seq[i]]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (s.empty())
            s.push({seq[i], i});
        if (freq[s.top()[0]] < freq[seq[i]])
        {
            while (!s.empty() && freq[s.top()[0]] < freq[seq[i]])
            {
                ngf[s.top()[1]] = seq[i];
                s.pop();
            }
            s.push({seq[i], i});
        }
        else
            s.push({seq[i], i});
    }

    for (int i = 0; i < n; i++)
        cout << ngf[i] << " ";
    return 0;
}