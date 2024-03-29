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
bool isPalindromdll(Node* head, Node* tail){
        while (head != tail && tail != head -> previous){
            if(head -> value != tail -> value){
                return false;
            }
            head = head -> next;
            tail = tail -> previous;
        }
        return true;
    }
int main(){
    DoublyLinkedLits dll;
    dll.insertAtEnd(1);
    dll.insertAtEnd(2);
    dll.insertAtEnd(2);
    dll.insertAtEnd(1);
    dll.display();
    cout << isPalindromdll(dll.head, dll.tail) << endl;
    dll.display();
    return 0;
} 
