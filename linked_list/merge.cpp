/*Given Pointer/Reference to the head of the linked list, the task is to Sort the given linked list using Merge Sort.
Note: If the length of linked list is odd, then the extra node should go in the first list while splitting.*/

    Node *getmiddle(Node *head){
        Node *slow=head;
        Node *fast=head->next;
        while(fast!=NULL&&fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
        return slow;
    }
    
    Node *merge(Node *left,Node *right){
        if(left==NULL)
            return right;
        if(right==NULL)
            return left;
        Node *start=new Node(-1);
        Node *temp=start;
        while(left!=NULL && right!=NULL){
            if(left->data<right->data){
                temp->next=left;
                temp=left;
                left=left->next;
            }
            else{
                temp->next=right;
                temp=right;
                right=right->next;
            }
        }
        while(left!=NULL){
            temp->next=left;
            temp=left;
            left=left->next;
        }
        while(right!=NULL){
            temp->next=right;
            temp=right;
            right=right->next;
        }
        start=start->next;
        return start;
    }
    Node* mergeSort(Node* head) {
        // your code here
        if(head==NULL || head->next==NULL){
            return head;
        }
        Node *middle=getmiddle(head);
        Node *left=head;
        Node *right=middle->next;
        middle->next=NULL;
        left=mergeSort(left);
        right=mergeSort(right);
        Node *ans=merge(left,right);
        return ans;
    }
