/**
 * https://www.acmicpc.net/problem/14501
 *
 * solution: 1일차부터 순서대로 상담 진행여부를 정해는 Brute Force방식으로 진행
 * 최대 n일차까지 진행가능하고 상담 하는 경와와 안하는 경우 2가지로 나뉘므로
 * O(2^n)의 시간 복잡도를 가진다.
 * n <= 15 이므로 2^15 = 32768 사용가능한 방식!
 */
#include <iostream>
using namespace std;
int t[15];
int p[15];
int income = 0;
void Counseling(int now, int money, int n)
{
    if (now > n)
        return;
    if (now == n)
    {
        income = max(income, money);
        return;
    }

    // 상담을 안하는 경우
    Counseling(now + 1, money, n);
    // 상담을 하는 경우
    Counseling(now + t[now], money + p[now], n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> t[i] >> p[i];
    Counseling(0, 0, n);
    cout << income;
    return 0;
}