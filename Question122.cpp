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
bool isPalindrom(Node* &head){
    // find the middle element
    Node* slow = head;
    Node* fast = head;
    while(fast && fast -> next){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    // now slow is pointing to middle element
    // 2. break the linked list in the middle
    Node* current = slow -> next;
    Node* previous = slow;
    slow -> next = NULL;
    // 3. revers the 2nd half of linked list
    while(current){
        Node* nextNode = current -> next;
        current -> next = previous;
        previous = current;
        current = nextNode;
    }
    // 4. check if the linked lists are equal
    Node* head1 = head;
    Node* head2 = previous;
    while(head2){
        if(head1 -> value != head2 -> value){
            return false;
        }
        head1 = head1 -> next;
        head2 = head2 -> next;
    }
    return true;
}
int main(){
    LinkedList ll1;
    ll1.insertAtTail(1);
    ll1.insertAtTail(2);
    ll1.insertAtTail(3);
    // ll1.insertAtTail(4);
    ll1.insertAtTail(2);
    ll1.insertAtTail(1);
    ll1.display();
    cout << isPalindrom(ll1.head);
    return 0;
}

