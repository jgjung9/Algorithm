/**
 * https://www.acmicpc.net/problem/2263
 *
 * solution: 트리의 순회 방식에 따른 재귀적 특성을 이용해
 * 루트를 뽑아내고 왼쪽 오른쪽 서브 트리를 만들어 다시 재귀적으로 루트를 뽑아낸다
 * 프리 오더의 경우 루트를 방문하고 왼쪽 서브트리의 루트를 방문해야 하므로
 * 서브트리의 루트를 왼쪽부터 재귀적으로 뽑아서 출력하면 자동적으로 프리오더 방식으로 출력된다.
 */
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> inorder(100000), postorder(100000);
void makeTree(int root, int inStart, int inEnd, int postStart, int postEnd)
{
    cout << root << ' ';
    if (inEnd == inStart)
        return;

    int lInStart, lInEnd;
    int rInStart, rInEnd;
    int lPostStart, lPostEnd;
    int rPostStart, rPostEnd;

    lInStart = inStart, lInEnd = inStart - 1;
    rInStart = inEnd + 1, rInEnd = inEnd;
    for (int i = inStart; i <= inEnd; i++)
    {
        if (inorder[i] == root)
        {
            lInEnd = i - 1;
            rInStart = i + 1;
            break;
        }
    }

    lPostStart = postStart, rPostEnd = postEnd - 1;
    lPostEnd = postStart + (lInEnd - lInStart);
    rPostStart = lPostEnd + 1;

    if (lInStart <= lInEnd)
    {
        int lRoot = postorder[lPostEnd];
        makeTree(lRoot, lInStart, lInEnd, lPostStart, lPostEnd);
    }
    if (rInStart <= rInEnd)
    {
        int rRoot = postorder[rPostEnd];
        makeTree(rRoot, rInStart, rInEnd, rPostStart, rPostEnd);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> inorder[i];
    for (int i = 0; i < n; i++)
        cin >> postorder[i];

    int root = postorder[n - 1];
    makeTree(root, 0, n - 1, 0, n - 1);
    return 0;
}