#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int value;
    Node* next;
    Node(int data){
        value = data;
        next = NULL;
    }
};
class LinkedList{
    public:
    Node* head;
    LinkedList(){
        head = NULL;
    } 
    void insertAtTail(int value){
        Node* new_node = new Node(value);
        if(head==NULL){ // linked list is empty
        head = new_node;
            return;
        }
        Node* temp = head;
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = new_node;
    }
    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp -> value << " -> ";
            temp = temp -> next;
        }
        cout << "NULL" << endl;
    }
};
Node* reversOrder(Node* &head){
    Node* previous_pointer = NULL;
    Node* current_pointer = head;
    // current_pointer -> next
    // move all 3 pointers by one steps
    while(current_pointer != NULL){
        Node* next_pointer = current_pointer -> next;
        current_pointer -> next = previous_pointer;
        previous_pointer = current_pointer;
        current_pointer = next_pointer;
    }
    // when this loop ends, previous_pointer pointing to my last node which is new head
    Node* new_head = previous_pointer;
    return new_head;
}
int main(){
    LinkedList ll;
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(4);
    ll.insertAtTail(5);
    ll.insertAtTail(6);
    ll.display();
    ll.head = reversOrder(ll.head);
    ll.display();
    return 0;
}
