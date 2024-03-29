#include<bits/stdtr1c++.h>
// #include<iostream>
// #include<list>
using namespace std;
int main(){
    list<int> l1 = {1, 2, 3};
    auto itr = l1.begin();
    auto itr2 = l1.end();
    auto itr3 = l1.rbegin();
    auto itr4 = l1.rend();
    cout << *itr << endl;
    cout << *itr2 << endl;
    cout << *itr3 << endl;
    cout << *itr4 << endl;
    return 0;
}
