/**
 * https://www.acmicpc.net/problem/2089
 *
 * 진법 변환
 * 음수의 모듈러 연산의 경우 프로그래밍 언어마다 처리방식이 다르다
 * 따라서 프로그래밍 언어 별로 처리 방식을 확인한 후
 * 적절하게 진법 변환처리를 진행해야 한다.
 */
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string answer;
    int n;
    cin >> n;
    do
    {
        int remain = n % -2;
        n = n / -2;
        if (remain == -1)
        {
            n = n + 1;
            remain = 1;
        }
        answer += to_string(remain);
    } while (n != 0);

    reverse(answer.begin(), answer.end());
    cout << answer;
    return 0;
}