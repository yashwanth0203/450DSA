/*Given two decimal numbers represented by two linked lists of size N and M respectively. The task is to 
return a linked list that represents the sum of these two numbers.For example, the number 190 will be 
represented by the linked list, 1->9->0->null, similarly 25 by 2->5->null. Sum of these two numbers is 
190 + 25 = 215, which will be represented by 2->1->5->null. You are required to return the head of the 
linked list 2->1->5->null.*/

/*The method of adding two numbers is like how we usually do addition from right to left.Tis is addTwoLists*/
/*The method of adding from right to left.Tis is addTwoLists2*/
#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
struct Node* reverse(struct Node* &head){
        struct Node* curr=head;
        struct Node* forward=NULL;
        struct Node* prev=NULL;
        while(curr!=NULL){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
    struct Node* addTwoLists1(struct Node* &l1, struct Node* &l2){
      struct Node* dummy=new struct Node(0);
      struct Node* temp=dummy;
        int carry=0;
        //l1=reverse(l1);
        //l2=reverse(l2);
        while(l1!=NULL || l2!=NULL || carry){
            int sum=0;
            if(l1!=NULL){
                sum+=l1->data;
                l1=l1->next;
            }

            if(l2!=NULL){
                sum+=l2->data;
                l2=l2->next;
            }
            sum+=carry;
            carry=sum/10;
            struct Node* node=new struct Node(sum%10);
            temp->next=node;
            temp=temp->next;
        }
        return dummy->next;
    }
    struct Node* addTwoLists(struct Node* &l1, struct Node* &l2)
    {
        struct Node* dummy=new struct Node(0);
        struct Node* temp=dummy;
        int carry=0;
        l1=reverse(l1);
        l2=reverse(l2);
        while(l1!=NULL || l2!=NULL || carry){
            int sum=0;
            if(l1!=NULL){
                sum+=l1->data;
                l1=l1->next;
            }

            if(l2!=NULL){
                sum+=l2->data;
                l2=l2->next;
            }
            sum+=carry;
            carry=sum/10;
            struct Node* node=new struct Node(sum%10);
            temp->next=node;
            temp=temp->next;
        }
        return reverse(dummy->next);
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
	struct Node *head1 = new struct Node(9);
	head1->next = new struct Node(4);
	head1->next->next = new struct Node(2);

    struct Node *head2 = new struct Node(9);
	head2->next = new struct Node(6);
	head2->next->next = new struct Node(4);
    head2->next->next->next = new struct Node(5);
    struct Node*res=addTwoLists(head1,head2);
    
    printList(res);
    struct Node *head3 = new struct Node(9);
	head3->next = new struct Node(4);
	head3->next->next = new struct Node(2);

    struct Node *head4 = new struct Node(9);
	head4->next = new struct Node(6);
	head4->next->next = new struct Node(4);
    head4->next->next->next = new struct Node(5);
    struct Node*res1=addTwoLists1(head3,head4);
    printList(res1);
	return 0;
}