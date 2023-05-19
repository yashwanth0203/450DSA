/*Write a function findFirstLoopNode() that checks whether a given Linked List contains a loop. If the 
loop is present then it returns point to the first node of the loop. Else it returns NULL.*/

/*1. If a loop is found, initialize a slow pointer to head, let fast pointer be at its position. 
2. Move both slow and fast pointers one node at a time. 
3. The point at which they meet is the start of the loop.*/

// C++ program to return first node of loop.
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int key;
	struct Node* next;
};

Node* newNode(int key)
{
	Node* temp = new Node;
	temp->key = key;
	temp->next = NULL;
	return temp;
}

// A utility function to print a linked list
void printList(Node* head)
{
	while (head != NULL) {
		cout << head->key << " ";
		head = head->next;
	}
	cout << endl;
}

Node* detectAndRemoveLoop(Node* head)
{
	if (head == NULL || head->next == NULL)
		return NULL;

	Node *slow = head, *fast = head;
	slow = slow->next;
	fast = fast->next->next;
	while (fast && fast->next) {
		if (slow == fast)
			break;
		slow = slow->next;
		fast = fast->next->next;
	}

	if (slow != fast)
		return NULL;
	
	slow = head;
	while (slow != fast) {
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}
/*1. Create a temporary node and a pointer temp.
2. While head is not null:
    *Check if head->next is null then return null.
    *Check if head->next is temp than break.
    *Create a nex pointer to a node and point it to head->next.
    *Point head->next to temp.
    *Update head to nex.
3. Return head.*/
Node* detectLoop(Node* head)
{
 
    Node* temp = new Node;
    while (head != NULL) {
        if (head->next == NULL) {
            return NULL;
        }
        if (head->next == temp) {
            break;
        }
        Node* nex = head->next;
        head->next = temp;
        head = nex;
    }
 
    return head;
}

/*We can also use the concept of hashing in order to detect the first node of the loop. The idea is 
simple just iterate over the entire linked list and store node addresses in a set(C++ STL) one by one, 
while adding the node address into the set check if it already contains that particular node address if 
not then add node address to set if it is already present in the set then the current node is the first 
node of the loop. */

Node* detectCycle(Node* A){
    // declaring map to store node address
    unordered_set<Node*> uset;
    Node *ptr = A;
 
    // Default consider that no cycle is present
    while (ptr != NULL) {
        // checking if address is already present in map
        if (uset.find(ptr) != uset.end())
          return ptr;
        // if address not present then insert into the set
        else
            uset.insert(ptr);
         
        ptr = ptr->next;
    }
    return NULL;
}
int main()
{
	Node* head = newNode(50);
	head->next = newNode(20);
	head->next->next = newNode(15);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(10);

	head->next->next->next->next->next = head->next->next;

	Node* res = detectAndRemoveLoop(head);
	if (res == NULL)
		cout << "Loop does not exist";
	else
		cout << "Loop starting node is " << res->key;
	return 0;
}

