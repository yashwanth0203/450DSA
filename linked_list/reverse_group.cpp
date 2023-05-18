/*Given a linked list of size N. The task is to reverse every k nodes (where k is an input to the function)
in the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should
be considered as a group and must be reversed*/

#include <iostream>

struct node {
    int data;
    node* next;
};

struct node* reverse(struct node* head, int k)
{
    if (head == NULL) {
        return NULL;
    }

    node* prev = NULL;
    node* curr = head;
    node* forward = NULL;

    int count = 0;

    while (curr != NULL && count < k) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    if (curr != NULL) {
        head->next = reverse(curr, k);
    }

    return prev;
}

struct node* newNode(int data)
{
    node* temp = new node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void printList(struct node* head)
{
    while (head != NULL) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main()
{
    struct node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    int k = 2;

    std::cout << "Original linked list: ";
    printList(head);

    head = reverse(head, k);

    std::cout << "Reversed linked list: ";
    printList(head);

    return 0;
}
