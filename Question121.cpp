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
void removeCycle(Node* & head){
    Node* slow = head;
    Node* fast = head;
    do{
        slow = slow -> next;
        fast = fast -> next -> next;
    }while(slow != fast);
    fast = head;
    while(slow -> next != fast -> next){
        slow = slow -> next;
        fast = fast -> next;
    }
    slow -> next = NULL;
}
 bool detectCycle(Node* head){
    if(!head){
        return false;
    }
    Node* slow = head;
    Node* fast = head;
    while(fast && fast -> next){
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast){
             cout << slow -> value << endl;
            return true;
        }
    }
    return false;
}
int main(){
    LinkedList ll1;
    ll1.insertAtTail(1);
    ll1.insertAtTail(2);
    ll1.insertAtTail(3);
    ll1.insertAtTail(4);
    ll1.insertAtTail(5);
    ll1.insertAtTail(6);
    ll1.insertAtTail(7);
    ll1.insertAtTail(8);
    ll1.head -> next-> next-> next-> next-> next-> next-> next-> next = ll1.head -> next-> next;
    cout << detectCycle(ll1.head) << endl;
    removeCycle(ll1.head);
    cout << "After removing cycle -> ";
    cout << detectCycle(ll1.head) << endl;
    ll1.display();
    return 0;
}
