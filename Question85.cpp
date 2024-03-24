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
void deleteDuplicate(Node* &head){
    Node* current_node = head;
    while(current_node != NULL){
        while(current_node -> next != NULL && current_node -> value == current_node -> next -> value){
            Node* temp = current_node  -> next; // node to be delete
            current_node -> next = current_node -> next -> next;
            free(temp);
        }
        // this loops end when current node & next node value are different
        // or linked list end
        current_node = current_node -> next;
    }
}
int main(){
    LinkedList ll;
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(3);
    ll.insertAtTail(4);
    ll.insertAtTail(4);
    ll.insertAtTail(4);
    ll.insertAtTail(5);
    ll.insertAtTail(6);
    ll.insertAtTail(1);
    ll.display();
    deleteDuplicate(ll.head);
    ll.display();
    return 0;
}
