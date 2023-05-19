/*iven a singly linked list consisting of N nodes. The task is to remove duplicates (nodes with duplicate 
values) from the given list (if exists).
Note: Try not to use extra space. Expected time complexity is O(N). The nodes are arranged in a sorted way.*/

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

// A utility function to print a linked list
void printList(Node* head)
{
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

Node* removeDuplicates(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* curr = head;
    Node* forward = head->next;

    while (curr->next != NULL && forward != NULL) {
        if (curr->data == forward->data) {
            while (forward != NULL && curr->data == forward->data) {
                Node* temp = forward;
                forward = forward->next;
                delete temp;
            }
            curr->next = forward;
        } else {
            curr = forward;
            if (forward != NULL) {
                forward = forward->next;
            }
        }
    }

    return head;
}

int main()
{
	Node* head = newNode(2);
	head->next = newNode(3);
	head->next->next = newNode(4);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(4);

	printList(head);
    removeDuplicates(head);
    printList(head);
	return 0;
}