/*Given a linked list of N nodes such that it may contain a loop.A loop here means that the last node of 
the link list is connected to the node at position X(1-based index). If the link list does not have any 
loop, X=0.Remove the loop from the linked list, if it is present, i.e. unlink the last node which is 
forming the loop.*/

/*The function begins with a check to see if the linked list is either empty (head == NULL) or has only 
one node (head->next == NULL). In either case, there is no loop, so the function returns without making 
any changes.If the linked list has more than one node, two pointers slow and fast are initialized to the 
head of the linked list. slow moves one step at a time (slow = slow->next), and fast moves two steps at a 
time (fast = fast->next->next). This approach is commonly known as the "tortoise and hare" algorithm.
The while loop continues until fast reaches the end of the linked list (fast == NULL) or encounters a 
null next pointer (fast->next == NULL). If a loop exists, slow and fast will eventually meet at some point.
If slow and fast are found to be equal (slow == fast), indicating the presence of a loop, the loop is 
broken out of.Inside the loop detection condition, there are two scenarios to handle:
If the loop starts from the first node (slow == fast == head), we iterate fast until it reaches the last 
node of the loop (fast->next != slow). This ensures that fast will point to the last node before the start
of the loop.Otherwise, if the loop does not start from the first node, we iterate both slow and fast until
their next pointers are equal (slow->next != fast->next). This will give us the last node before the start
of the loop.After finding the last node before the start of the loop, fast->next is set to NULL to break 
the loop and remove the circular connection.In summary, the code first detects the presence of a loop 
using the Floyd's cycle-finding algorithm. If a loop is found, it then determines the last node before 
the start of the loop and breaks the loop by setting the next pointer of that node to NULL. This 
effectively removes the loop from the linked list.*/

#include <bits/stdc++.h>
using namespace std;
struct node {
    int data;
    node* next;
};

struct node* newNode(int data) {
    node* temp = new node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void removeLoop(node* head)
{
    if(head==NULL || head->next==NULL)
        return;
        node*slow=head , *fast=head;
        slow=slow->next;
        fast=fast->next->next;
        while(fast && fast->next){
            if(slow==fast)
             break;
            slow=slow->next;
            fast=fast->next->next;
        }
        if(slow==fast){
            slow=head;
            if(slow==fast){
                while(fast->next!=slow) fast=fast->next;
            }
            else{
                while(slow->next!=fast->next){
                    slow=slow->next;
                    fast=fast->next;
                }
            }
         fast->next=NULL;
        }
        
        
    }

bool detectloop(struct node* head){
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



int main() {
    struct node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    
    head->next->next->next->next->next = head->next;
    cout<<"Before Removing loop"<<endl;
    if(detectloop(head))
        cout<<"Loop found"<<endl;
    else
        cout<<"No loop found"<<endl;
    removeLoop(head);
    cout<<"After Removing loop"<<endl;
    if(detectloop(head))
        cout<<"Loop found"<<endl;
    else
        cout<<"No loop found"<<endl;
    return 0;
}