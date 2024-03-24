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
int getLength(Node* head){
    Node* temp = head;
    int length = 0;
    while(temp != NULL){
        length++;
        temp = temp -> next;
    }
    return length;
}
Node* moveHeadyByK(Node* head, int k){
    Node* ptr = head;
    while(k--){
        ptr = ptr -> next;
    }
    return ptr;
}
Node* getIntersection(Node* head1, Node* head2){
    // step-1: calculate lengths of both linked lists
    int length1 = getLength(head1);
    int length2 = getLength(head2);
    // step-2: find difference betwwen linked list & move longer linkedlist ptr
    Node* ptr1, *ptr2;
    if(length1 > length2){ // ll1 is longer
        int k = length1 - length2;
        ptr1 = moveHeadyByK(head1, k);
        ptr2 = head2;
    }
    else{ //ll2 is longer
        int k = length2 - length1;
        ptr1 = head1;
        ptr2 = moveHeadyByK(head2, k);
    }
    // step-3: compare ptr1 & ptr2 nodes
    while(ptr1){
        if(ptr1 == ptr2){
            return ptr1;
        }
        ptr1 = ptr1 -> next;
        ptr2 = ptr2 -> next;
    }
    return NULL;
}
int main(){
    LinkedList ll1;
    ll1.insertAtTail(1);
    ll1.insertAtTail(2);
    ll1.insertAtTail(3);
    ll1.insertAtTail(4);
    ll1.insertAtTail(5);
    ll1.display();
    LinkedList ll2;
    ll2.insertAtTail(6);
    ll2.insertAtTail(7);
    ll2.head -> next -> next = ll1.head -> next -> next -> next;
    ll2.display();
    Node* interction = getIntersection(ll1.head, ll2.head);
    if(interction){
        cout << interction -> value <<endl;
    }
    else{
        cout << -1;
    }
    return 0;
}
