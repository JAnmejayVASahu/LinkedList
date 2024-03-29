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
class CircularLinkedLists{
    public:
    Node* head;
    CircularLinkedLists(){
        head = NULL;
    }
    void display(){
        Node* temp = head;
        do{
            cout << temp -> value <<" -> ";
            temp = temp -> next;
        }while(temp != head);
        cout << endl;
    }
    void insertAtStart(int value){
    Node* new_node = new Node(value);
    if(head == NULL){
        head = new_node;
        new_node -> next = head;
        return;
        }
        Node* tail = head;
        while(tail -> next != head){
            tail = tail -> next;
        }
        // now tail is pointing  to the last  node
        tail -> next = new_node;
        new_node -> next = head;
    }
    void deletAtStart(){
        if(head == NULL){
            return;
        }
        Node* temp = head;
        Node* tail = head;
        while(tail -> next != head){
            tail = tail -> next;
        }
        head = head -> next;
        tail -> next = head;
        free(temp);
    }
};
int main(){
    CircularLinkedLists cll;
    cll.insertAtStart(3);
    cll.insertAtStart(2);
    cll.insertAtStart(1);
    cll.insertAtStart(4);
    cll.insertAtStart(5);
    cll.display();
    cll.deletAtStart();
    cll.display();
    return 0;
}
