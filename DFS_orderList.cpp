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

void inOrder_tree(struct Node *root)
{
    stack<Node *> s;
    Node *curr = root;
    while (curr != NULL || s.empty() == false)
    {
        while (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }

        curr = s.top();
        s.pop();

        cout << curr->data << " ";
        curr = curr->right;
    }
}

void inOrder(struct Node* node)
{
    if(node==NULL)
    {
        return;
    }
    inOrder(node->left);
    cout<<node->data<<" ";
    inOrder(node->right);
}

void postOrder(struct Node* node)
{
    if(node==NULL)
    {
        return;
    }
    postOrder(node->left);
    
    postOrder(node->right);
    cout<<node->data<<" ";
}

void preOrder(struct Node* node)
{
    if(node==NULL)
    {
        return;
    }
    cout<<node->data<<" ";
    preOrder(node->left);
    preOrder(node->right);
}


int main()
{
    struct Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);

    //      1
    //    2   3
    //  4   5

    inOrder(root);
    cout<<endl;
    
    postOrder(root);
    cout<<endl;

    preOrder(root);
    return 0;
}