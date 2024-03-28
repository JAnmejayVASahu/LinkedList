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
Node* rotateByK(Node* &head, int k){
    // 1.find length of ll
    int n= 0;
    // 2.find the tail
    Node* tail = head;
    while(tail -> next){
        n++; //finding the length
        tail = tail -> next; // finding last node
    }
    n++; // for including last node
    k = k%n;
    if(k == 0){
        return 0;
    }
    tail -> next = head;
    // 3.travers n-k
    Node* temp = head;
    for(int i=1; i<=n; i++){
        temp = temp -> next;
    }
    // temp is now pointing to (n-k)th node
    Node* newhead = temp -> next;
    temp -> next = NULL;
    return newhead;
}
int main(){
    LinkedList ll1;
    ll1.insertAtTail(1);
    ll1.insertAtTail(2);
    ll1.insertAtTail(3);
    ll1.insertAtTail(4);
    ll1.insertAtTail(5);
    ll1.insertAtTail(6);
    ll1.display();
    ll1.head = rotateByK(ll1.head, 3);
    ll1.display();
    return 0;
}
