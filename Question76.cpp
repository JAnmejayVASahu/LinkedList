#include<bits/stdc++.h>
using namespace std;
class Node{
        public:
        int data;
        Node* next;
        Node(int value){
            data=value;
            next = NULL;
        }
    };
int main(){
    Node* n = new Node(1);
    cout << n->data << " "<<n->next<< endl;
    return 0;
}
