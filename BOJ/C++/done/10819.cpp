/**
 * https://www.acmicpc.net/problem/10819
 *
 * solution: 입력받은 수들을
 * 순열로 모든 방법으로 나열해 식을 계산하여 최댓값을 구한다.
 * +a 그리디 방식으로도 풀 수 있음
 */
#include <iostream>
#include <algorithm>
using namespace std;
bool visited[8] = {false};
int number[8];
int ans[8];
int answer = -1e9;

int Calculate(int n)
{
    int ret = 0;
    for (int i = 0; i < n - 1; i++)
        ret += abs(ans[i] - ans[i + 1]);
    return ret;
}

void Permuation(int n, int idx)
{
    if (idx == n)
        answer = max(answer, Calculate(n));

    for (int i = 0; i < n; i++)
    {
        if (visited[i])
            continue;
        visited[i] = true;
        ans[idx] = number[i];
        Permuation(n, idx + 1);
        visited[i] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> number[i];
    sort(number, number + n);
    Permuation(n, 0);
    cout << answer;
    return 0;
}