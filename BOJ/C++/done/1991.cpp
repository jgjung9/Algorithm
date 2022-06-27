#include <iostream>
using namespace std;

struct node
{
    char value;
    node *left, *right;
};

void pre(node *root)
{
    if (root == nullptr)
        return;
    cout << root->value;
    pre(root->left);
    pre(root->right);
}

void in(node *root)
{
    if (root == nullptr)
        return;
    in(root->left);
    cout << root->value;
    in(root->right);
}

void post(node *root)
{
    if (root == nullptr)
        return;
    post(root->left);
    post(root->right);
    cout << root->value;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    node *tree[26];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        tree[i] = new node();
        tree[i]->value = 'A' + i;
    }

    char parent, left, right;
    for (int i = 0; i < n; i++)
    {
        cin >> parent >> left >> right;
        if (left != '.')
            tree[parent - 'A']->left = tree[left - 'A'];
        if (right != '.')
            tree[parent - 'A']->right = tree[right - 'A'];
    }

    pre(tree[0]);
    cout << '\n';
    in(tree[0]);
    cout << '\n';
    post(tree[0]);

    return 0;
}