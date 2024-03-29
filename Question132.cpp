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
    void insertAtStart(int value){
        Node* new_node = new Node(value);
        if(head == NULL){
            head = new_node;
            tail = new_node;
            return;
        }
        new_node -> next = head;
        head -> previous = new_node;
        head = new_node;
        return; 
    }
};
int main(){
    DoublyLinkedLits dll;
    dll.insertAtStart(1);
    dll.insertAtStart(2);
    dll.insertAtStart(3);
    dll.display();
    return 0;
}
