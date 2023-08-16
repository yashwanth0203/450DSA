
/*Given two singly linked lists of size N and M, write a program to get the point where two linked lists intersect each other.*/
#include <bits/stdc++.h>
using namespace std;
struct Node {
  int data;
  Node *next;
};
struct Node* newNode(int data) {
    Node* temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}
int intersectPoint(Node* head1, Node* head2)
{
    Node* temp1 = head1;

      Node* temp2 = head2;

      while (temp1 != temp2) {

        temp1 = temp1 == nullptr ? head2 : temp1 -> next;

        temp2 = temp2 == nullptr ? head1 : temp2 -> next;

      }

      return temp2->data;
}
int main(){
struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);
    struct Node* head2 = newNode(7);
    head2->next = newNode(9);
    head2->next->next = newNode(3);
    head2->next->next->next = newNode(4);
    head2->next->next->next->next = newNode(5);
    cout<<intersectPoint(head,head2);
}
