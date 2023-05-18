/*Given a pointer to the head node of a linked list, the task is to reverse the linked list. We need to
reverse the list by changing the links between nodes.*/

/*Take three pointers curr,prev and next .Initialize current to head and prev,next to NULL.At each iteration
move next to next of current make current point to previous prev to curr and then current to next.After
coming out of loop assign head to prev since current would have been null by that time.*/

// Iterative C++ program to reverse a linked list
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node* next;
	Node(int data)
	{
		this->data = data;
		next = NULL;
	}
};

struct LinkedList {
	Node* head;
	LinkedList() { head = NULL; }

	void reverse()
	{
		Node* current = head;
		Node *prev = NULL, *next = NULL;

		while (current != NULL) {
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		head = prev;
	}

    void recur_reverse(Node* p)
    {
        if(p->next==NULL){
            head=p;
            return;
        }

        recur_reverse(p->next);
        Node *q=p->next;
        q->next=p;
        p->next=NULL;
    }
	void print()
	{
		struct Node* temp = head;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
        cout<<endl;
	}

	void push(int data)
	{
		Node* temp = new Node(data);
		temp->next = head;
		head = temp;
	}
};

int main()
{
	LinkedList ll;
	ll.push(20);
	ll.push(4);
	ll.push(15);
	ll.push(85);

	cout << "Given linked list\n";
	ll.print();
    cout << "\nReversed linked list \n";
	ll.reverse();
    ll.print();
    ll.recur_reverse(ll.head);
	cout << "\nReversed linked list \n";
	ll.print();
	return 0;
}


