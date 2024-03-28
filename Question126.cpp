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
        if(head == NULL){ // linked list is empty
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
Node* swapAdjacent(Node* &head){
    // base case
    if(head == NULL || head -> next == NULL){
        return head;
    }
    // recursive case
    Node* SeconfNode = head -> next;
    head -> next = swapAdjacent(SeconfNode -> next);
    SeconfNode -> next = head; // reverse between  first and secon node
    return SeconfNode;
}
int main(){
    LinkedList ll1;
    ll1.insertAtTail(1);
    ll1.insertAtTail(2);
    ll1.insertAtTail(3);
    ll1.insertAtTail(4);
    ll1.insertAtTail(5);
    ll1.insertAtTail(6);
    // ll1.insertAtTail(7);
    ll1.display();
    ll1.head = swapAdjacent(ll1.head);
    ll1.display();
    return 0;
}
