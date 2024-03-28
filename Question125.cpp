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
Node* reorderdLL(Node* &head){
    //  can check if ll ha st list 3 node
    // 1.finding the middle element
    Node* slow = head;
    Node* fast = head;
    while(fast && fast -> next){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    // now slow is pointing to  the middle element
    // 2. separate the ll & revers second half
    Node* current = slow -> next;
    slow -> next = NULL;
    Node* previous = slow;
    while(current){
        Node* nextPtr = current -> next;
        current -> next = previous;
        previous = current;
        current = nextPtr;
    }
    // 3.merging the two half of the linked list
    Node* ptr1 = head; // this is the linked list first half
    Node* ptr2 = previous; // this is the linked of 2nd half
    while(ptr1 != ptr2){
        Node* temp = ptr1 -> next;
        ptr1->next = ptr2;
        ptr1 = ptr2;
        ptr2 = temp;
    }
    return head;
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
    ll1.head = reorderdLL(ll1.head);
    ll1.display();
    return 0;
}
