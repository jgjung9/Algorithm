/**
 * https://www.acmicpc.net/problem/11726
 *
 * hint: 마지막 놓는 타일이 | ㅡ 따라 상황을 나눌 수 있다.
 * | 일 경우 dp[n-1] 가지수 만큼 앞에 올 수 있고
 * ㅡ 일 경우 dp[n -2] 가지수 만큼 앞에 올 수 있다.
 * 따라서 dp[n] = dp[n-1] + dp[n-2] 이다.
 */
#include <iostream>
using namespace std;
const int MAX_SIZE = 1001;

int main()
{
    int dp[MAX_SIZE];
    dp[1] = 1;
    dp[2] = 2;
    int n;
    cin >> n;
    for (int i = 3; i <= n; i++)
        dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
    cout << dp[n];
    return 0;
}