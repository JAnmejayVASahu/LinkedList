#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int value;
    Node* previous;
    Node* next;
    Node(int data){
        value = data;
        previous = NULL;
        next = NULL;
    }
};
class DoublyLinkedLits{
    public:
    Node* head;
    Node* tail;
    DoublyLinkedLits(){
        head = NULL;
        tail = NULL;
    }
    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp -> value <<" <-> ";
            temp = temp -> next;
        }
        cout << endl;
    }
    void insertAtEnd(int value){
        Node* new_node = new Node(value);
        if(tail == NULL){
            head = new_node;
            tail = new_node;
            return;
        }
        tail -> next = new_node;
        new_node -> previous = tail;
        tail = new_node;
        return; 
    }
    void deletAtStart(){
        if(head == NULL){
            return;
        }
        Node* temp = head;
        head = head -> next;
        // if(head != NULL){
        //     head -> previous = NULL;
        // }
        // free(temp);
        if(head == NULL){ // if this linked list had 1 node
            tail = NULL;
        }
        else{
            head -> previous = NULL;
        }
        free(temp);
        return;
    }
};
int main(){
    DoublyLinkedLits dll;
    dll.insertAtEnd(1);
    dll.insertAtEnd(2);
    dll.insertAtEnd(3);
    dll.insertAtEnd(4);
    dll.display();
    dll.deletAtStart();
    dll.display();
    return 0;
}
