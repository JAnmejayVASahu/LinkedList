#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int value;
    Node* next;
    Node(int data){
        value=data;
        next=NULL;
    }
};
void insertAtHead(Node* &head, int value){
    Node* new_Node=new Node(value);
    new_Node->next=head;
    head=new_Node;
}
void deleteAtHead(Node* &head){
    Node* temp = head; // node to be delete
    head=head->next;
    free(temp);
}
void deleteAtPosition(Node* &head, int position){
    if(position==0){
        deleteAtHead(head);
        return;
    }
    int current_position = 0;
    Node* previous = head;
    while(current_position != position-1){
        previous = previous -> next;
        current_position++;
    }
    // Previous pointer pointing to  node at position-1
    Node* temp = previous -> next; // Node to be delete
    previous-> next = previous -> next->next;
    // free(temp);
}
void display(Node* head){
    Node* temp=head;
    while(temp != NULL){
        cout << temp->value <<" -> ";
        temp=temp->next;
    }
    cout << " NULL"<< endl;
}
int main(){
    Node* head=NULL;
    insertAtHead(head, 5);
    insertAtHead(head, 2);
    insertAtHead(head, 8);
    insertAtHead(head, 4);
    display(head);
    deleteAtPosition(head,2);
    display(head);
    return 0;
}
