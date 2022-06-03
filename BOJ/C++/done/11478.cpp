/**
 * https://www.acmicpc.net/problem/11478
 *
 * solution: 부분 문자열을 집합에 넣고
 * 집합의 원소의 개수를 출력한다.
 */
#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    set<string> ans;
    string str;
    cin >> str;
    for (int i = 1; i <= str.size(); i++)
    {
        for (int j = 0; j <= str.size() - i; j++)
            ans.insert(str.substr(j, i));
    }
    cout << ans.size();
    return 0;
}