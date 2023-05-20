/*Given two linked lists sorted in increasing order, create a new linked list representing the 
intersection of the two linked lists. The new linked list should be made with its own memory the original 
lists should not be changed.
Note: The linked list elements are not necessarily distinct.*/
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* findIntersection(Node* head1, Node* head2) {
    Node* first = head1;
    Node* second = head2;
    Node* dummy = new Node(0);
    Node* res = dummy;

    while (first != NULL && second != NULL) {
        if (first->data > second->data) {
            second = second->next;
        } else if (first->data < second->data) {
            first = first->next;
        } else {
            Node* temp = new Node(first->data);
            res->next = temp;
            res = res->next;
            first = first->next; // Move first pointer to the next node
            second = second->next; // Move second pointer to the next node
        }
    }

    return dummy->next;
}

void printList(Node* &head)
{
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

int main()
{
	Node* head1 = new Node(1);
	head1->next = new Node(2);
	head1->next->next = new Node(3);
	head1->next->next->next = new Node(4);
	head1->next->next->next->next = new Node(6);

	Node* head2 = new Node(2);
	head2->next = new Node(4);
	head2->next->next = new Node(6);
	head2->next->next->next = new Node(8);

	Node* res = findIntersection(head1,head2);
	printList(res);
	return 0;
}