/**
 * https://www.acmicpc.net/problem/1931
 *
 * solution: Greedy
 * 회의가 끝나는 시간 기준으로 정렬하고
 * 끝나는 시간이 같은 경우 시작시간을 기준으로 정렬해 그리디 방식으로
 * 답을 찾는다.
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, start, done, ans = 0;
vector<pair<int, int>> meeting;

bool compare(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
        return a.first < b.first;
    else
        return a.second < b.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> start >> done;
        meeting.push_back(make_pair(start, done));
    }
    sort(meeting.begin(), meeting.end(), compare);
    done = 0;

    for (int i = 0; i < meeting.size(); i++)
    {
        if (done <= meeting[i].first)
        {
            done = meeting[i].second;
            ans++;
        }
    }
    cout << ans;
    return 0;
}