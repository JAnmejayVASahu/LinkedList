#include<iostream>
#include<list>
using namespace std;
int main(){
    // range based loop.
    list<int> l1 = {1, 2, 3};
    // using iterator
    for(auto itr = l1.begin(); itr != l1.end(); itr++){
        cout << *itr <<" ";
    }
    return 0;
}
