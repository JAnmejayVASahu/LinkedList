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
    void reversdll(Node* &head, Node* &tail){
        Node* currentPtr = head;
        while(currentPtr){
            Node* nextPtr = currentPtr -> next;
            currentPtr -> next = currentPtr -> previous;
            currentPtr -> previous = nextPtr;
            currentPtr = nextPtr;
        }
        Node* new_head = tail;
        tail = head;
        head = new_head;
    }
};
int main(){
    DoublyLinkedLits dll;
    dll.insertAtEnd(1);
    dll.insertAtEnd(2);
    dll.insertAtEnd(3);
    dll.insertAtEnd(4);
    dll.display();
    dll.reversdll(dll.head, dll.tail);
    dll.display();
    return 0;
} 
