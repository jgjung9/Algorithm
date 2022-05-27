/**
 * https://www.acmicpc.net/problem/17298
 *
 * hint: 스택을 활용해서 구할 수 있다.
 * 입력 받은 값들을 배열에 저장하고 차례대로 처음 입력받은 값과 인덱스를 스택에 저장한다.
 * 다음 값을 스택에 들어있는 값과 비교해 작을 경우 스택에 값과 인덱스를 넣는다
 * 클 정도 스택의 값이 작아질때까지 스택의 값을 빼고 해당 인덱스를 nge[인덱스] = 현재 값으로 밀어준다.
 */
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> seq(n, 0);
    vector<int> nge(n, -1);
    stack<vector<int>> s;
    for (int i = 0; i < n; i++)
        cin >> seq[i];

    s.push({seq[0], 0});
    for (int i = 1; i < n; i++)
    {
        if (s.top()[0] < seq[i])
        {
            while (!s.empty() && s.top()[0] < seq[i])
            {
                nge[s.top()[1]] = seq[i];
                s.pop();
            }
            s.push({seq[i], i});
        }
        else
            s.push({seq[i], i});
    }

    for (int i = 0; i < n; i++)
        cout << nge[i] << " ";
    return 0;
}