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
void insertAtPosition(Node* &head, int value, int position){
    if(position==0){
        insertAtHead(head, value);
        return;  
    }
    Node* new_node = new Node(value);
    Node* temp = head;
    int current_position = 0;
    while(current_position != position-1){
        temp = temp->next;
        current_position++;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}
void insertAtTail(Node* &head, int value){
    Node* new_node = new Node(value);
    Node* temp=head;
    while(temp->next != NULL){
        temp=temp->next;
    }
    temp->next=new_node;
}
void updationAtPstion(Node* &head, int position, int value){
    Node* temp=head;
    int current_position = 0;
    while(current_position != position){
        temp=temp->next;
        current_position++;
    }
    temp->value = value;
}
void deleteAtTail(Node* &head){
    Node* second_last = head; // node to be delete
    while(second_last->next->next != NULL){
        second_last = second_last -> next;
    }
    Node* temp = second_last->next;
    second_last->next = NULL;
    free(temp);
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
    display(head);
    insertAtHead(head, 2);
    display(head);
    insertAtTail(head, 8);
    display(head);
    insertAtPosition(head, 4, 1);
    display(head);
    updationAtPstion(head, 2, 9);
    display(head);
    deleteAtTail(head);
    display(head);
    return 0;
}
