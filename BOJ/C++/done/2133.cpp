/**
 * https://www.acmicpc.net/problem/2133
 *
 * hint: 3xN 타일을 채우기 위해서는 반드시 ㅡ 타일 3개가 수직으로 놓거나
 * | 타일 위나 아래에 ㅡ 타일을 놓아야 한다.
 * | 타일을 놓을 경우 | 타일 2개와 ㅡ 타일이 그밑이나 위에 배치되는 경우
 * | 타일옆에 ㅡ 놓는 경우로 나눌 수 있을 것이다.
 * | 타일 옆에 ㅡ 두면 아래, 혹은 위 수직축 1칸을 채우기 위해서 ㅡㅡ가 올수 밖에 없고
 * 그 위에 | 타일이 올 수 있게 된다. 이와 같은 과정을 반복하면
 * |ㅡㅡ| |ㅡㅡㅡ| |ㅡㅡㅡㅡ| 와 같이 ||사이에 ㅡ가 하나씩 추가되는 경우가 계속 발생한다.
 * D(n)을 타일을 놓는 경우의 수라고 할 때,
 * D(n) = D(n-2) * 3 + D(n-4) * 2 + D(n-6) * 2 ... D(2) * 2 + 2
 * n이 홀수 일 경우 타일을 놓을 수 있는 경우는 존재하지 않는다.
 */
#include <iostream>
#include <vector>
using namespace std;
const int MAX_SIZE = 31;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> dp(MAX_SIZE, 0);
    dp[0] = 1, dp[2] = 3;
    for (int i = 4; i <= n; i += 2)
    {
        dp[i] = 3 * dp[i - 2];
        for (int j = 0; j < i - 2; j += 2)
            dp[i] += 2 * dp[j];
    }

    cout << dp[n];
    return 0;
}