/**
 * https://www.acmicpc.net/problem/1963
 *
 * solution: BFS를 통한 최단거리 구하기 + 에라스토테네스의 체
 * 에라토스테네스의 체로 10000 미만의 모든 소수를 판정한다.
 * 한자리의 숫자를 변경하고 그 숫자가 소수인 네자리 자연수이며, 방문한적이 없는경우
 * 방문을 진행한다.
 * 숫자의 변경은 shift를 응용한 방식으로 진행
 * -> 문자열로 변환해 자리수를 변경하고 해당값을 다시 정수변경하는 것도 가능
 * -> 문자열을 사용하는 방식이 훨씬 간결해 보임
 */
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int t, start, target;
bool isPrime[10000];
int visited[10000];

int leftShift(int n)
{
    return (n % 1000) * 10 + n / 1000;
}

int rightShift(int n)
{
    return (n % 10) * 1000 + n / 10;
}

void BFS(int node)
{
    queue<int> q;
    int dist = 1;
    visited[node] = dist;
    q.push(node);

    while (!q.empty())
    {
        node = q.front(), q.pop();
        dist = visited[node];

        if (node == target)
        {
            cout << dist - 1 << '\n';
            return;
        }

        for (int i = 0; i < 40; i++)
        {
            int nextNode = node;
            int n = i / 10;
            for (int j = 0; j < n; j++)
                nextNode = leftShift(nextNode);
            nextNode = (i % 10) * 1000 + nextNode % 1000;
            for (int j = 0; j < n; j++)
                nextNode = rightShift(nextNode);
            if (nextNode < 1000 || nextNode >= 10000 || !isPrime[nextNode])
                continue;
            if (visited[nextNode])
                continue;
            visited[nextNode] = dist + 1;
            q.push(nextNode);
        }
    }
    cout << "Impossible\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i < 10000; i++)
    {
        if (!isPrime[i])
            continue;
        for (int j = i + i; j < 10000; j += i)
            isPrime[j] = false;
    }

    cin >> t;
    while (t--)
    {
        memset(visited, 0, sizeof(visited));
        cin >> start >> target;
        BFS(start);
    }
    return 0;
}