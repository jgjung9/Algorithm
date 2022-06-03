/**
 * https://www.acmicpc.net/problem/14889
 *
 * soultion:
 * 스타트팀에서 사람을 선택한다고 보면,
 * 사람을 선택하고 선택하지 않고로 나뉘게 된다. (선택하지 않으면 자동으로 링크팀)
 * 스타트팀 인원이 n / 2 명 보다 클 경우 선택은 불가능하다.
 * 스타트팀과 링크팀 모두 선발이 완료된 후 시너지 값을 차를 구하고 그 값을 기존 값과 비교해
 * 더 작을 경우 업데이트 한다. 초기 값 설정은 차로 만들수 없는 큰값으로 설정한다.
 */
#include <iostream>
#include <vector>
using namespace std;

int s[20][20] = {0};
int ans = 10000;
vector<int> start;
vector<int> link;

int check(int m)
{
    int startValue = 0, linkValue = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == j)
                continue;
            startValue += s[start[i]][start[j]];
            linkValue += s[link[i]][link[j]];
        }
    }
    return abs(startValue - linkValue);
}

void go(int n, int idx)
{
    if (start.size() > n / 2)
        return;
    if (link.size() > n / 2)
        return;
    if (start.size() == n / 2 && link.size() == n / 2)
        ans = min(ans, check(n / 2));

    start.push_back(idx);
    go(n, idx + 1);
    start.pop_back();

    link.push_back(idx);
    go(n, idx + 1);
    link.pop_back();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> s[i][j];
    go(n, 0);
    cout << ans;
    return 0;
}