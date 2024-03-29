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
};
void deleteSameNextPrevious(Node* &head, Node* &tail){
    Node* currentNode = tail -> previous;
    while(currentNode != head){
        Node* previousNode = currentNode -> previous;
        Node* nextNode = currentNode -> next;
        if(previousNode -> value == nextNode -> value){
            previousNode -> next = nextNode;
            nextNode -> previous = previousNode;
            free(currentNode);
        }
        currentNode = previousNode;
    }
}
int main(){
    DoublyLinkedLits dll;
    dll.insertAtEnd(2);
    dll.insertAtEnd(1);
    dll.insertAtEnd(2);
    dll.insertAtEnd(1);
    dll.display();
    deleteSameNextPrevious(dll.head, dll.tail);
    dll.display();
    return 0;
}
