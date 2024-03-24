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
        if(head==NULL){ // linked list is empty
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
Node* recussiveRevers(Node* &head){
    // base case
    if(head == NULL || head -> next == NULL){
        return head;
    }
    Node* new_head = recussiveRevers(head -> next);
    head -> next -> next = head;
    head -> next = NULL;
    return new_head;
}
int main(){
    LinkedList ll;
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(4);
    ll.insertAtTail(5);
    ll.insertAtTail(6);
    ll.display();
    ll.head = recussiveRevers(ll.head);
    ll.display();
    return 0;
}

// 089 Given the head of a linked list, reverse the nodes of the list K at a time & return the modified list.
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
        if(head==NULL){ // linked list is empty
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
Node* recuseAtTime(Node* &head, int k){
    Node* previous_pointer = NULL;
    Node* current_pointer = head;
    int counter = 0; // counting first k node
    while(current_pointer != NULL && counter < k){ // reversing first k node
        Node* next_pointer = current_pointer -> next;
        current_pointer -> next = previous_pointer;
        previous_pointer = current_pointer;
        current_pointer = next_pointer;
        counter++;
    }
    //  current  will give us (k+1)th node
    if(current_pointer != NULL){
        Node* new_head = recuseAtTime(current_pointer , k); // recursive call
        head -> next = new_head;
    }
    return previous_pointer; // previous_pointer will give the new_head of conneced linked list
}
int main(){
    LinkedList ll;
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(4);
    ll.insertAtTail(5);
    ll.insertAtTail(6);
    ll.display();
    ll.head = recuseAtTime(ll.head,5);
    ll.display();
    return 0;
}

