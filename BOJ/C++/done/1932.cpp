/**
 * https://www.acmicpc.net/problem/1932
 *
 * hint:  0 | 1 2 | 3 4 5 | 4 5 6 7 |....
 * 형식으로 삼각형 인덱스가 진행될 때 각 인덱스 자리에 들어가는 수를 t[i]
 * d[1] = d[0] + t[1], d[2] = d[1] + t[2]
 * 왼쪽 변과 오른쪽 변에 있는 인덱스의 경우 d[i] = d[j] + t[i] (j는 i 바로 위의 점)
 * 변에 있는 점이 아닌경우 d[i] = max(d[j] + t[i]) (j는 i의 위 2점)
 * 해당 점화 식을 통해 모든 밑변의 d[i] 값을 모두 구하고 최대값을 출력
 */
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> t(n * (n + 1) / 2);
    for (int i = 0; i < t.size(); i++)
        cin >> t[i];
    vector<int> dp(t.size());
    dp[0] = t[0];

    int answer = dp[0];
    for (int i = 1; i < n; i++)
    {
        int startIndex = i * (i + 1) / 2;
        for (int j = 0; j < i + 1; j++)
        {
            if (j == 0)
                dp[startIndex + j] = dp[startIndex - i] + t[startIndex];
            else if (j == i)
                dp[startIndex + j] = dp[startIndex - 1] + t[startIndex + j];
            else
                dp[startIndex + j] = max(dp[startIndex + j - i - 1], dp[startIndex + j - i]) + t[startIndex + j];

            if (i == n - 1)
                answer = max(answer, dp[startIndex + j]);
        }
    }
    cout << answer;
    return 0;
}