/*A number N is represented in Linked List such that each digit corresponds to a node in linked list. 
You need to add 1 to it.*/
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
Node* reverse(Node *head){
        Node* curr=head,*prev=NULL,*forward=NULL;
        while(curr!=NULL){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }

Node* addOne(Node *head) 
{
    Node* new_head = reverse(head);
    Node* current = new_head;
    Node* prev = NULL;
    
    int carry = 1; // Start with carry = 1 since we are adding 1
    
    while(current != NULL){
        int sum = current->data + carry;
        carry = sum / 10; // Update the carry
        
        current->data = sum % 10; // Update the node value
        
        prev = current;
        current = current->next;
    }
        
    if(carry == 1){
        // If there is still a carry, create a new node with value 1
        prev->next = newNode(1);
    }
    
    return reverse(new_head);
}


int main()
{
	Node* head = newNode(9);
	head->next = newNode(9);
	head->next->next = newNode(9);
	printList(head);
    head=addOne(head);
    printList(head);
	return 0;
}