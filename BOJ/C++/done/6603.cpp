/**
 * https://www.acmicpc.net/problem/6603
 *
 * solution: k개의 수를 정렬하고
 * 해당 수를 뽑을 지 말지 선택하는 경우로 문제를 해결 할 수 있다.
 */
#include <iostream>
#include <algorithm>
using namespace std;
int number[12];
int ans[6];

void Lotto(int k, int i, int idx)
{
    if (idx == 6)
    {
        for (int i = 0; i < 6; i++)
            cout << ans[i] << ' ';
        cout << '\n';
        return;
    }
    if (i == k)
        return;

    ans[idx] = number[i];
    Lotto(k, i + 1, idx + 1);

    Lotto(k, i + 1, idx);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int k;
    while (true)
    {
        cin >> k;
        if (k == 0)
            break;
        for (int i = 0; i < k; i++)
            cin >> number[i];
        sort(number, number + k);
        Lotto(k, 0, 0);
        cout << '\n';
    }
    return 0;
}