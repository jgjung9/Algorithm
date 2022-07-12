/**
 * https://www.acmicpc.net/problem/15658
 *
 * solution: Brute Force
 * 남아 있는 연산자중 하나를 골라 계산을 진행한다.
 * 계속 반복하여 수열의 끝에 도달하면 그 결과 최솟값, 최댓값과 비교하여
 * 최소, 최대를 업데이트 해준다.
 */
#include <iostream>
using namespace std;
int n, maxValue = -1e9, minValue = 1e9;
int seq[11];
int op[4] = {0};
int used[4] = {0};

int calculate(int v1, int v2, int oper)
{
    if (oper == 0)
        return v1 + v2;
    else if (oper == 1)
        return v1 - v2;
    else if (oper == 2)
        return v1 * v2;
    else
        return v1 / v2;
}

void solve(int idx, int res)
{
    if (idx == n)
    {
        maxValue = max(maxValue, res);
        minValue = min(minValue, res);
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        if (used[i] < op[i])
        {
            used[i]++;
            solve(idx + 1, calculate(res, seq[idx], i));
            used[i]--;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> seq[i];
    for (int i = 0; i < 4; i++)
        cin >> op[i];
    solve(1, seq[0]);
    cout << maxValue << '\n';
    cout << minValue;
    return 0;
}