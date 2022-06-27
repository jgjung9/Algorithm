/**
 * https://www.acmicpc.net/problem/2250
 *
 * solution: 중위순회를 활용해 각 노드의 위치를 너비 값의 위치를 정해준다
 * 루트를 찾고 루트를 시작점으로 중위 순회를 하고
 * 깊이가 동일한 값은 dep[h] 에 푸쉬하고 이후
 * 각 깊이에 dep[h][0] dep[h].back() 값의 차이를 통해 너비를 구한다.
 * 너비가 최대 값이 될 때 해당하는 높이를 구한다.
 */
#include <iostream>
#include <vector>
using namespace std;
struct node
{
    int order;
    node *left, *right;
};

int n, p, l, r, order = 1;
node *tree[20001];
vector<int> dep[20001];

void inorder(node *root, int h)
{
    if (root == nullptr)
        return;
    inorder(root->left, h + 1);
    root->order = order++;
    dep[h].push_back(root->order);
    inorder(root->right, h + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    int depth = 0, width = 0;
    vector<bool> isRoot(20001, true);
    for (int i = 1; i <= n; i++)
        tree[i] = new node();

    for (int i = 0; i < n; i++)
    {
        cin >> p >> l >> r;

        if (l != -1)
        {
            tree[p]->left = tree[l];
            isRoot[l] = false;
        }
        if (r != -1)
        {
            tree[p]->right = tree[r];
            isRoot[r] = false;
        }
    }

    int root;
    for (int i = 1; i <= n; i++)
    {
        if (isRoot[i])
        {
            root = i;
            break;
        }
    }
    inorder(tree[root], 1);

    for (int i = 1; i <= n; i++)
    {
        if (dep[i].size() == 0)
            break;

        int w = dep[i].back() - dep[i][0] + 1;
        if (w > width)
        {
            width = w;
            depth = i;
        }
    }

    cout << depth << ' ' << width;

    return 0;
}