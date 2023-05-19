/*Given a linked list of N nodes. The task is to check if the linked list has a loop. Linked list can
contain self loop.*/

/*The first approach is to assign an element to INT_MIN or INT_MAX. If there is loop these will be encountered
again and we return true else we return false out of loop*/

#include <bits/stdc++.h>
using namespace std;
struct node {
    int data;
    node* next;
};

bool detectloop(struct node* head){
    while(head!=NULL){
        if(head->data=INT_MIN)
            return true;
        head->data=INT_MIN;
        head=head->next;
    }
    return false;
}

bool detectloop1(struct node* head){
        node *slow=head;
        node *fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow){
                return true;
            }    
        }
        return false;
}
struct node* newNode(int data) {
    node* temp = new node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}


/*But what if the data can be be anything even INT_MIN or INT_MAX. Then the above code doesnt work.In that
case we need to think of slow and fast pointer approach. You can try this if you want but the thing is
slow pointer moves one step further and fast pointer moves two steps further.If there is a loop they 
eventually meet at one point. This approach can be used then.*/
int main() {
    struct node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);


    head->next->next->next->next->next = head->next;

    if (detectloop1(head))
        cout << "Loop found in the linked list" << std::endl;
    else
        cout << "No loop found in the linked list" << std::endl;

    return 0;
}

