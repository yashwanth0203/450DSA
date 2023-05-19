/*Given an unsorted linked list of N nodes. The task is to remove duplicate elements from this unsorted 
Linked List. When a value appears in multiple nodes, the node which appeared first should be kept, all 
others duplicates are to be removed.*/
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

Node * removeDuplicates( Node *head) 
    {
      if(head==NULL || head->next==NULL){
            return head;
        }
        
        map<int,int>mp;
        Node*curr=head;
        Node*prev=curr;
        
        mp[curr->data]=1;
        curr=curr->next;
        
        while(curr!=NULL ){
            if(mp[curr->data]!=1){
                mp[curr->data]=1;
                prev=curr;
            }else{
                prev->next=curr->next;
                delete(curr);
            }
            curr=prev->next;
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
    head->next->next->next->next->next = newNode(3);
	printList(head);
    removeDuplicates(head);
    printList(head);
	return 0;
}