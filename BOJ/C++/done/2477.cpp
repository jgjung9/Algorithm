/**
 * https://www.acmicpc.net/problem/2477
 *
 * solution: 가로 세로의 가장 큰 값을 구하고 곱한다
 * 가로의 가장 큰 변과 세로의 가장 큰 변이 만나는 꼭지점의 대각선 위치해 있는 점을 기준으로
 * 사격형의 넓이를 구하고 그 값을 빼준다.
 */
#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, dir;
    int edges[6];
    cin >> n;
    int idx, max = 0;
    for (int i = 0; i < 6; i++)
    {
        cin >> dir >> edges[i];
        if (max < edges[i])
        {
            max = edges[i];
            idx = i;
        }
    }

    int pre = (idx - 1 + 6) % 6;
    int next = (idx + 1) % 6;
    int start = idx;
    if (edges[pre] > edges[next])
        start = pre;

    int area = edges[start] * edges[(start + 1) % 6] - (edges[(start + 3) % 6] * edges[(start + 4) % 6]);
    cout << area * n;
    return 0;
}