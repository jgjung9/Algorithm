/**
 * https://www.acmicpc.net/problem/14425
 *
 * solution: N, M <= 10,000
 * N개의 문자열을 배열에 놓고 M개의 문자열이 해당 배열에 들어 있는지 확인을 하게되면
 * O(NxM)의 시간복잡도로 문제를 해결하게 된다.
 * NxM <= 100,000,000 이므로 해결 가능한 방법이 된다.
 * => 시간초과 문자열 비교의 시간 복잡도를 생각하지 않아서 발생
 * 문자열 길이 조건 500제한으로
 * 문자열 비교 연산의 시간 복잡도는 최대 500이 된다.
 * 따라서 500xNxM이므로 시간초과 발생
 *
 * -> C++ set을 이용해 문제 풀이
 */
#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, cnt;
    string str;
    cin >> n >> m;
    set<string> strSet;
    while (n--)
    {
        cin >> str;
        strSet.insert(str);
    };
    while (m--)
    {
        cin >> str;
        if (strSet.find(str) != strSet.end())
            cnt++;
    }
    cout << cnt;
    return 0;
}