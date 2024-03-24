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
    insertAtTail(head, 2);
    insertAtTail(head, 8);
    insertAtTail(head, 4);
    display(head);
    updationAtPstion(head, 2, 9);
    display(head);
    return 0;
}
