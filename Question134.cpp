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
    void insertAtPosition(int value, int k){
        // assum k is less or equal to the length of doubly linked list
        Node* temp = head;
        int count = 1; // index base of 1
        while(count < (k-1)){
            temp = temp -> next;
            count++;
        }
        // temp will be pointing to  the node at (k-1)th position
        Node* new_node = new Node(value);
        new_node -> next = temp -> next;
        temp -> next = new_node;
        new_node -> previous = temp;
        new_node -> next -> previous = new_node;
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
    dll.insertAtPosition(5, 3);
    dll.display();
    return 0;
}

