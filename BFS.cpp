#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

void bfs(struct Node *curr)
{
    if (curr == NULL)
    {
        return;
    }

    cout << curr->data << " ";
    
    bfs(curr->left);
    
    bfs(curr->right);
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    //      1
    //    2   3
    //  4   5

    bfs(root);
    return 0;
}