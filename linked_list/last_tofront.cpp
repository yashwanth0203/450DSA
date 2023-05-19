/*Write a function that moves the last node to the front in a given Singly Linked List.*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* next;
};

Node* newNode(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->next = NULL;
	return temp;
}

void printList(Node* head)
{
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

void moveToFront(Node* &head)
{
    if (head == NULL || head->next == NULL)
        return;

    Node* secLast = NULL;
    Node* last = head;

    while (last->next != NULL) {
        secLast = last;
        last = last->next;
    }
  

    secLast->next = NULL;
  

    last->next = head;
    head = last;
}

int main()
{
	Node* head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(3);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(5);
	printList(head);
    moveToFront(head);
    printList(head);
	return 0;
}