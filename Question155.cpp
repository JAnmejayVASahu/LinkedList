#include<iostream>
#include<list>
using namespace std;
int main(){
    list<int> l1 = {1, 2, 3};
    // using iterator revers travers
    for(auto itr = l1.rbegin(); itr != l1.rend(); itr++){
        cout << *itr <<" ";
    }
    return 0;
}
