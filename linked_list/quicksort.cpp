/*Sort the given Linked List using quicksort. which takes O(n^2) time in worst case and O(nLogn) in average and best cases, otherwise you may get TLE.*/

node* partition(node*head,node*tail){
    node *curr=head,*prev=head,*pivot=head;
    while(curr!=tail->next){
        if(curr->data<pivot->data){
            swap(curr->data,prev->next->data);
            prev=prev->next;
        }
        curr=curr->next;
    }
    swap(prev->data,pivot->data);
    return prev;
}
void quicksort(node *head,node *tail){
    if(!head or !tail or (head==tail))return;
    node* pivot=partition(head,tail);
    quicksort(head,pivot);
    quicksort(pivot->next,tail);
    return;
}
void quickSort(struct node **headRef) {
    node* head=*headRef;
    node* tail=head;
    if(!head or !head->next)return;
    while(tail->next)tail=tail->next;
    quicksort(head,tail);
}