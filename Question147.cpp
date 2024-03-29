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
    void printCircular(){
        Node* temp = head;
        for(int i=0; i<=15; i++){
            cout << temp -> value <<" -> ";
            temp = temp -> next;
        }
        cout << endl;
    }
    void insertAtEnd(int value){
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
        head = new_node;
    }
};
int main(){
    CircularLinkedLists cll;
    cll.insertAtEnd(3);
    cll.insertAtEnd(2);
    cll.insertAtEnd(1);
    cll.display();
    cll.printCircular();
    return 0;
}
