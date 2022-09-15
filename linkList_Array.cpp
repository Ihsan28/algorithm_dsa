#include <iostream>
using namespace std;

int fact_recursion(int num)
{

    if (num <= 1)
    {
        return 1;
    }
    else
    {
        return num * fact_recursion(num - 1);
    }
}

int fibonacchi_recursion(int no)
{
    if (no == 0)
    {
        return 0;
    }
    else if (no == 1 || no == 2)
    {
        return 1;
    }
    else
    {
        return fibonacchi_recursion(no - 1) + fibonacchi_recursion(no - 2);
    }
}

void circular_shift_array(int arr[6], int length)
{

    int last_index = arr[length - 1];
    for (int i = length - 1; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = last_index;
    int j = 0;
    while (j < length)
    {
        cout << arr[j];
        j++;
    }
}

class Node
{
public:
    int data;
    Node *next;
};

void push_circular_linkList(Node **head_ref, int data)
{
    Node *ptr_new = new Node();
    ptr_new->data = data;
    ptr_new->next = *head_ref;

    if (*head_ref != NULL)
    {
        Node *temp = *head_ref;
        while (temp->next != *head_ref)
        {
            temp = temp->next;
        }
        temp->next = ptr_new;
    }
    else
    {
        ptr_new->next = ptr_new;
        *head_ref = ptr_new;
    }
}

void print_circular_linkList(Node *head)
{
    Node *temp = head;
    while (temp->next != head)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void delete_node_linkList(Node **head, int key)
{
    if (*head == NULL)
    {
        return;
    }

    if ((*head)->data == key && (*head)->next == *head)
    {
        free(*head);
        *head = NULL;
        return;
    }

    Node *last = *head;

    if ((*head)->data == key)
    {
        while (last->next != *head)
        {
            last = last->next;
        }
        last->next = (*head)->next;
        free(*head);
        *head = (*head)->next;
        return;
    }

    while (last->next->data != key && last->next != *head)
    {
        last = last->next;
    }

    Node *temp;
    if (last->next->data == key)
    {
        temp = last->next;
        last->next = temp->next;
        free(temp);
    }
    else
    {
        cout << "no such data in list";
    }
}


int main()
{
    // recursion
    int fact_res = fact_recursion(5);
    cout << fact_res<< endl;

    // fibonacchi series
    for (int counter = 0; counter < 20; counter++)
    {
        cout<< fibonacchi_recursion(counter)<<" ";
    }

    int arr[] = {5, 2, 4, 1, 4, 2};
    int length = sizeof(arr) / sizeof(int);
    circular_shift_array(arr, length);

    //print circular link list
    Node *head = NULL;

    push_circular_linkList(&head, 2);
    push_circular_linkList(&head, 3);
    push_circular_linkList(&head, 4);
    push_circular_linkList(&head, 5);
    push_circular_linkList(&head, 7);

    cout << "print before deletion" << endl;
    // print_circular_linkList(head);

    delete_node_linkList(&head, 5);

    cout << "\nprint after deletion" << endl;
    // print_circular_linkList(head);

    return 0;
}
