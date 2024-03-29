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
    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp -> value <<" <-> ";
            temp = temp -> next;
        }
        cout << endl;
    }
    void insertAtEnd(int value){
        Node* new_node = new Node(value);
        if(tail == NULL){
            head = new_node;
            tail = new_node;
            return;
        }
        tail -> next = new_node;
        new_node -> previous = tail;
        tail = new_node;
        return; 
    }
};
vector <int> pairSumDll(Node* head, Node* tail, int x){
    vector <int> ans{-2, 1};
    while(head != tail){
        int sum = head -> value + tail -> value;
        if(sum == x){
            ans[0] = head -> value;
            ans[1] = tail -> value;
        }
        if(sum > x){ // i need smal value, i will move my tail back
            tail = tail -> previous;
        }
        else{
            head = head -> next;
        }
    }
    return ans;
}
int main(){
    DoublyLinkedLits dll;
    dll.insertAtEnd(2);
    dll.insertAtEnd(5);
    dll.insertAtEnd(6);
    dll.insertAtEnd(8);
    dll.insertAtEnd(10);
    dll.display();
    vector <int> ans = pairSumDll(dll.head, dll.tail, 10);
    cout << ans[0] << " " << ans[1] << endl;
    dll.display();
    return 0;
} 
