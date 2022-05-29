/**
 * https://www.acmicpc.net/problem/1107
 *
 * solution: brute force
 * 현재 채널이 100에 있고 가려고 하는 채널이 입력 채널이 N이라고 할 때 (N > 100)
 * +만을 눌렀을 때 버튼을 눌러야 하는 횟수는 N - 100 이다.
 * 따라서 최소 횟수이므로 2N 채널로 가서 -만을 눌렀을때 눌러야 하는 횟수는
 * +만을 눌렀을 때 가는 횟수보다 무조건 많으므로 사실상 2N이상의 채널은 무의미하다.
 * 2N 보다 작으면서 망가진 버튼을 제외하고 만들 수 있는 모든 채널을 탐색하여 최소값을 뽑을 수 있다.
 * N < 100 이면 0~99 까지 채널 중 만들 수 있는 모든 채널을 탐색하면 된다.
 */
#include <iostream>
#include <cmath>
using namespace std;

bool isPossible(int n, bool isBroken[])
{
    if (n == 0 && isBroken[0])
        return false;

    while (n > 0)
    {
        if (isBroken[n % 10])
            return false;
        n /= 10;
    }
    return true;
}

int Count(int i, int n)
{
    int cnt = 1;
    int temp = i / 10;
    while (temp > 0)
    {
        temp /= 10;
        cnt++;
    }

    if (i < n)
        cnt += n - i;
    else
        cnt += i - n;

    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    bool isBroken[10] = {false};
    int n, m, minCnt;
    cin >> n >> m;
    minCnt = n - 100 > 0 ? n - 100 : 100 - n;
    while (m--)
    {
        int x;
        cin >> x;
        isBroken[x] = true;
    }

    if (n < 100)
    {
        for (int i = 0; i < 100; i++)
            if (isPossible(i, isBroken))
                minCnt = min(minCnt, Count(i, n));
    }
    else
    {
        for (int i = 0; i <= 2 * n; i++)
            if (isPossible(i, isBroken))
                minCnt = min(minCnt, Count(i, n));
    }
    cout << minCnt;
    return 0;
}