/**
 * https://www.acmicpc.net/problem/5639
 *
 * solution: Binary Search Tree
 * 주어진 전위 순회 순서대로 트리에 값을 삽인한 후
 * 포스트 오더를 호출한다.
 */
#include <iostream>
#include <vector>
using namespace std;
int value;
class Node
{
public:
    Node(int value)
    {
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
    }
    int value;
    Node *left, *right;
};

void insertNode(Node *node, Node *root)
{
    Node *temp = root;
    while (temp != nullptr)
    {
        if (temp->value > node->value)
        {
            if (temp->left == nullptr)
            {
                temp->left = node;
                temp = nullptr;
            }
            else
                temp = temp->left;
        }
        else if (temp->value < node->value)
        {
            if (temp->right == nullptr)
            {
                temp->right = node;
                temp = nullptr;
            }
            else
                temp = temp->right;
        }
    }
}

void postOrder(Node *root)
{
    if (root->left != nullptr)
        postOrder(root->left);
    if (root->right != nullptr)
        postOrder(root->right);
    cout << root->value << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> value;
    Node *root = new Node(value);

    while (cin >> value)
    {
        if (value == EOF)
            break;
        Node *newNode = new Node(value);
        insertNode(newNode, root);
    }

    postOrder(root);
    return 0;
}