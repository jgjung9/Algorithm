/**
 * https://www.acmicpc.net/problem/17404
 *
 * solution: DP
 * 0 빨 1 초 2 파
 * A(n)(k) n 번째 집의 k색깔의 비용
 * n번째에 k색깔을 칠 했을 경우 비용의 합의 최소 값을 D[n][k]라 하면,
 * 첫번째 색깔이 0 (빨)일 때, D(n)(k) n 번째 집에 k를 칠하는 경우의 최솟값
 * 첫번째 색깔이 1 (초)일 때, D1(n)(k) n 번째 집에 k를 칠하는 경우의 최솟값
 * 첫번째 색깔이 2 (파)일 때, D2(n)(k) n 번째 집에 k를 칠하는 경우의 최솟값 이라고 하면
 * D(1)(2,3), D(2)(0)은 불가능한 경우로 굉장히 큰 값을 넣어준다.
 * D(n)(k) = min(D(n-1)(i)) + A(n)(k) (i != k)
 * D1, D2로 비슷한 형식으로 세팅해서 진행한다
 * min(D(n)(1,2), D1(n)(0,2), D2(n)(0,1))을 출력한다.
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> a(n + 1, vector<int>(3, 0));
    vector<vector<int>> d(n + 1, vector<int>(3, 0));
    vector<vector<int>> d1(n + 1, vector<int>(3, 0));
    vector<vector<int>> d2(n + 1, vector<int>(3, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 3; j++)
            cin >> a[i][j];

    if (n == 2)
    {
        d[2][0] = min(a[1][1], a[1][2]) + a[2][0];
        d[2][1] = min(a[1][0], a[1][2]) + a[2][1];
        d[2][2] = min(a[1][0], a[1][1]) + a[2][2];

        int answer = min(d[2][0], min(d[2][1], d[2][2]));
        cout << answer;
        return 0;
    }
    else
    {

        d[2][0] = 2000;
        d[2][1] = a[1][0] + a[2][1];
        d[2][2] = a[1][0] + a[2][2];

        d1[2][1] = 2000;
        d1[2][0] = a[1][1] + a[2][0];
        d1[2][2] = a[1][1] + a[2][2];

        d2[2][2] = 2000;
        d2[2][0] = a[1][2] + a[2][0];
        d2[2][1] = a[1][2] + a[2][1];
    }

    for (int i = 3; i <= n; i++)
    {
        d[i][0] = min(d[i - 1][1], d[i - 1][2]) + a[i][0];
        d[i][1] = min(d[i - 1][0], d[i - 1][2]) + a[i][1];
        d[i][2] = min(d[i - 1][0], d[i - 1][1]) + a[i][2];

        d1[i][0] = min(d1[i - 1][1], d1[i - 1][2]) + a[i][0];
        d1[i][1] = min(d1[i - 1][0], d1[i - 1][2]) + a[i][1];
        d1[i][2] = min(d1[i - 1][0], d1[i - 1][1]) + a[i][2];

        d2[i][0] = min(d2[i - 1][1], d2[i - 1][2]) + a[i][0];
        d2[i][1] = min(d2[i - 1][0], d2[i - 1][2]) + a[i][1];
        d2[i][2] = min(d2[i - 1][0], d2[i - 1][1]) + a[i][2];
    }
    int answer = min(d[n][1], d[n][2]);
    answer = min(answer, min(d1[n][0], d1[n][2]));
    answer = min(answer, min(d2[n][0], d2[n][1]));
    cout << answer;
    return 0;
}