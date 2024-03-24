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
//Soppose key always lessthan/equal linked list
void removeKthNodeFromEnd(Node* &head, int key){
    Node* ptr1 = head;
    Node* ptr2 = head;
    //move ptr2 by k steps
    int count = key;
    while(count--){
        ptr2 = ptr2 -> next;
    }
    if(ptr2 == NULL){ // key is equal to the length of linked list
        // we have to delete head node
        Node* temp = head;
        head = head -> next;
        free(temp);
        return;
    }
    //  now pyr2 is k steps ahead of ptr1
    //  when ptr2 is at null (end of list), ptr1 will be at node to be deleted
    while(ptr2 -> next != NULL){
        ptr1 = ptr1 -> next;
        ptr2 = ptr2 -> next;
    }
    // now ptr1 is pointing to the node before kth node from end
    //  node to be deleted is ptr1 -> next
    Node* temp = ptr1 -> next;
    ptr1 -> next = ptr1 -> next -> next;
    free(temp);
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
    removeKthNodeFromEnd(ll1.head, 2);
    ll1.display();
    return 0;
}
