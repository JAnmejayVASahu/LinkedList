#include<bits/stdc++.h>
using namespace std;
template<typename t>
class Node{
    public:
    t value;
    Node* next;
    Node(t data){
        value = data;
        next = NULL;
    }
};
int main(){
    // Node* node1 = new Node(3); // normaly we decalr that type
    Node<int>* node1 = new Node<int> (3);
    cout << node1 -> value << endl;
    Node<char>* node2 = new Node<char> ('a');
    cout << node2 -> value << endl;
    return 0;
}
