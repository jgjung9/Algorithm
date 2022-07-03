/**
 * https://www.acmicpc.net/problem/1094
 *
 * solution: 이분 탐색을 통한 막대 길이 구하기
 */
#include <iostream>
using namespace std;
int x;

void divide(int target)
{
    int sum = 64, bar = 64, cnt = 1;
    while (sum != target)
    {
        if (target > sum)
        {
            bar /= 2;
            sum += bar;
            cnt++;
        }
        else
        {
            bar /= 2;
            sum -= bar;
        }
    }
    cout << cnt << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> x;
    divide(x);
    return 0;
}