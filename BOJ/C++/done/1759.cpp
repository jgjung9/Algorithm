/**
 * https://www.acmicpc.net/problem/1759
 * consonant 자음 vowel 모음
 *
 * solution: l개중에 c개의 문자를 선택해 배열하는 것으로
 * nPm 순열의 n = l, m = c인 버전으로 생각할 수 있다.
 * 다만, 오름차순 조건으로 이전 값과 비교 했을 때 큰 값의 경우만 진행하고
 * 자음과 모음의 개수 제한이 있으면으로 자음과 모음의 개수 카운트를 진행한다.
 */
#include <iostream>
#include <algorithm>
using namespace std;
char ch[15];
bool visited[15];
char ans[15];
void Permutation(int c, int l, int idx, int con, int vo)
{
    if (idx == l)
    {
        // 자음이 2개보다 작으면
        if (con < 2)
            return;
        // 모음이 1개보다 작으면
        if (vo < 1)
            return;
        for (int i = 0; i < l; i++)
            cout << ans[i];
        cout << '\n';
        return;
    }

    for (int i = 0; i < c; i++)
    {
        if (visited[i])
            continue;
        if (idx > 0 && ans[idx - 1] > ch[i])
            continue;
        visited[i] = true;
        ans[idx] = ch[i];
        if (ch[i] == 'a' || ch[i] == 'e' || ch[i] == 'i' || ch[i] == 'o' || ch[i] == 'u')
            Permutation(c, l, idx + 1, con, vo + 1);
        else
            Permutation(c, l, idx + 1, con + 1, vo);
        visited[i] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int l, c;
    cin >> l >> c;
    for (int i = 0; i < c; i++)
        cin >> ch[i];
    sort(ch, ch + c);
    Permutation(c, l, 0, 0, 0);
    return 0;
}