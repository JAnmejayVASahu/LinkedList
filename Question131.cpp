#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int value;
    Node* previous;
    Node* next;
    Node(int data){
        value = data;
        previous = NULL;
        next = NULL;
    }
};
class DoublyLinkedLits{
    public:
    Node* head;
    Node* tail;
    DoublyLinkedLits(){
        head = NULL;
        tail = NULL;
    }
};
int main(){
    Node* new_node = new Node(3);
    DoublyLinkedLits dll;
    dll.head = new_node;
    dll.tail = new_node;
    cout << dll.head -> value << endl;
    return 0;
}
